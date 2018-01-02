#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QList>
#include <QTcpServer>
#include <client.h>

class Server : public QObject
{
    Q_OBJECT

public:
    static Server* Instance();

    QString startServer();
    void stopServer();
    bool isRunning();

    QString serverInfo();

    uint port;

signals:

private:
    static Server* instance;
    explicit Server(QObject *parent = nullptr);
    ~Server();

    QTcpServer* tcpServer;
    QList<Client*> clientList;

private slots:
    void startNewClient();
};

#endif // SERVER_H
