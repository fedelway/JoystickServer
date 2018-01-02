#ifndef PROGRAMPROTOCOL_H
#define PROGRAMPROTOCOL_H

#include <QByteArray>
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

}

#endif // PROGRAMPROTOCOL_H
