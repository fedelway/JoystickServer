#include "client.h"

#include <config.h>
#include "programprotocol.h"
#include <QDebug>
#include <qkeysequence.h>

#include <windowskeypresser.h>
#include <linuxkeypresser.h>

Client::Client(QAbstractSocket *socket, QObject *parent) : QObject(parent)
{
    this->socket = socket;

    connect(socket, &QAbstractSocket::readyRead, this, &Client::dataArrived);
    connect(socket, &QAbstractSocket::disconnected, this, &Client::onDisconnect);

#if defined(Q_OS_WIN)
    presser = new WindowsKeyPresser();
#elif defined(Q_OS_X11)
    presser = new LinuxKeyPresser();
#else
#   error ERROR SISTEMA OPERATIVO
#endif
}

Client::~Client()
{
    this->socket->close();
    delete this->socket;
    delete presser;
}

void Client::dataArrived()
{
    const bool newProtocol = true;
    Qt::Key key;
    bool press;

    Protocol::header_t header;
    Protocol::data_t data;

    if(newProtocol)
    {
        char serializedHeader[7] = {0};

        socket->read(serializedHeader,6);
        header = Protocol::deserializeHeader(serializedHeader);

        if(strcmp(header.validationString,Protocol::ValidationString))
        {
            //ERROR!
            socket->close();
            return;
        }

        char serializedData[4] = {0};
        socket->read(serializedData,3);

        data = Protocol::deserializeData(serializedData);

    }else{
        socket->read((char*)&header,Protocol::headerSize());

        if(strcmp(header.validationString,Protocol::ValidationString))
        {
            //ERROR!
            socket->close();
            return;
        }
        socket->read((char*)&data,Protocol::dataSize());
    }

    key = Config::Instance()->buttonToKeys.value((Joystick::Buttons)data.btn);
    press = (data.press == 1) ? true : false;

    presser->sendKeyPress(key,press);

    //Do something with data.
    qDebug() << QKeySequence(Config::Instance()->buttonToKeys.value((Joystick::Buttons)data.btn)).toString()
             << " "
             << QString::number(data.press);
}

void Client::onDisconnect()
{
    qDebug() << "DISCONNECT";
    this->deleteLater();
}
