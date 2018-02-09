#include "server.h"

#include <config.h>
#include <QTcpSocket>
#include <QDebug>
#include <QStringBuilder>
#include <QNetworkInterface>

Server* Server::instance;

Server::Server(QObject *parent) : QObject(parent)
{
    port = Config::Instance()->port;
    tcpServer = new QTcpServer();
}

Server::~Server()
{
    //Limpio todo.
    delete tcpServer;
    qDeleteAll(clientList.begin(),clientList.end());
    clientList.clear();
}

Server* Server::Instance()
{
    if(instance == nullptr)
        instance = new Server();

    return instance;
}

void Server::startNewClient()
{
    while(tcpServer->hasPendingConnections())
    {
        QTcpSocket* newSocket = tcpServer->nextPendingConnection();

        Client* newClient = new Client(newSocket,this);
        connect(newClient, &Client::destroyed, this, &Server::clientDeleted);

        this->clientList.append(newClient);

        qDebug() << "New Client";
    }
}

QString Server::startServer()
{
    bool result = tcpServer->listen(QHostAddress::Any,port);

    if(!result){
        return "No se pudo iniciar el servidor.";
    }

    connect(tcpServer, &QTcpServer::newConnection, this, &Server::startNewClient);

    return "";
}

void Server::stopServer()
{
    //Close server listening connection
    tcpServer->close();

    //Close every Client connection and destroy
    qDeleteAll(clientList.begin(),clientList.end());
    clientList.clear();
}

bool Server::isRunning()
{
    return tcpServer->isListening();
}

QString Server::serverInfo()
{
    //QString address = "Address: " + tcpServer->serverAddress().toString();
    QString address = "Address: ";

    foreach(const QHostAddress &addr, QNetworkInterface::allAddresses()){
        if(addr.protocol() == QAbstractSocket::IPv4Protocol && !addr.isLoopback())
            address.append(addr.toString());
    }

    QString separator = "\n" + QString(address.length(),QChar('-')) + "\n";
    QString port = "Port: " + QString::number(tcpServer->serverPort(),10);

    return address +
           separator +
           port;
}

void Server::clientDeleted(QObject* obj)
{
    Client* client = static_cast<Client*>(obj);

    //qDebug() << "CLIENT POINTER: " << client << "QOBJECT POINTER: " << obj;
    //qDebug() << "REMOVE SUCCESS: " << clientList.removeOne(client);
    //qDebug() << "CLIENT COUNT: " << clientList.size();
}
