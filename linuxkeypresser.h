#ifndef LINUXKEYPRESSER_H
#define LINUXKEYPRESSER_H

#include "qglobal.h"
#include "keypresser.h"

#ifdef Q_OS_X11
class LinuxKeyPresser : KeyPresser
{
public:
    LinuxKeyPresser();
    void sendKeyPress(Qt::Key);
};
#endif //Q_OS_LINUX

#endif // LINUXKEYPRESSER_H
