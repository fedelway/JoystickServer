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
    Protocol::header_t header;

    socket->read((char*)&header,Protocol::headerSize());

    if(strcmp(header.validationString,Protocol::ValidationString))
    {
        //ERROR!
        socket->close();
        return;
    }

    Protocol::data_t data;
    socket->read((char*)&data,Protocol::dataSize());

    Qt::Key key = Config::Instance()->buttonToKeys.value((Joystick::Buttons)data.btn);
    bool press = (data.press == 1) ? true : false;

    //Do something with data.
    qDebug() << QKeySequence(Config::Instance()->buttonToKeys.value((Joystick::Buttons)data.btn)).toString()
             << " "
             << QString::number(data.press);
}
