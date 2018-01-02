#include "client.h"

#include <config.h>
#include "programprotocol.h"
#include <QDebug>
#include <qkeysequence.h>

Client::Client(QAbstractSocket *socket, QObject *parent) : QObject(parent)
{
    this->socket = socket;

    connect(socket, &QAbstractSocket::readyRead, this, &Client::dataArrived);
}

Client::~Client()
{
    this->socket->close();
    delete this->socket;
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

    //Do something with data.
    qDebug() << QKeySequence(Config::Instance()->buttonToKeys.value((Joystick::Buttons)data.btn)).toString()
             << " "
             << QString::number(data.press);
}
