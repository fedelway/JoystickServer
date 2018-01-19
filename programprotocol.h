#ifndef PROGRAMPROTOCOL_H
#define PROGRAMPROTOCOL_H

#include <QByteArray>
#include <QString>
#include "qglobal.h"

namespace Protocol {

const char ValidationString[3+1] = {"MSG"};

typedef struct{
    char validationString[sizeof(ValidationString)];
    quint16 size;
}header_t;

typedef struct{
    quint16 btn;
    quint8 press;
}data_t;

int headerSize()
{
    return sizeof(ValidationString) + sizeof(quint16);
}

int dataSize()
{
    return sizeof(quint16) + sizeof(quint8);
}

header_t deserializeHeader(char* serialized)
{
    QString str = serialized;
    header_t header;

    strcpy(header.validationString,str.mid(0,3).toLocal8Bit().data());
    header.size = str.mid(3,3).toInt();

    return header;
}

data_t deserializeData(char* serializedData)
{
    QString str = serializedData;
    data_t data;

    data.btn = str.mid(0,2).toInt();
    data.press = str.at(2) == 'S' ? 1 : 0;

    return data;
}

}

#endif // PROGRAMPROTOCOL_H
