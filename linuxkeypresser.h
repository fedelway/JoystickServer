#ifndef LINUXKEYPRESSER_H
#define LINUXKEYPRESSER_H

#include "qglobal.h"
#include "keypresser.h"
#include <QHash>

#ifdef Q_OS_LINUX

#include "X11/keysym.h"
#include "X11/Xlib.h"

class LinuxKeyPresser : public KeyPresser
{
public:
    LinuxKeyPresser();
    void sendKeyPress(Qt::Key, bool press);

private:
    QHash<Qt::Key,KeySym> qtKeyToKeysym;

    void initializeMap();
};
#endif //Q_OS_LINUX

#endif // LINUXKEYPRESSER_H
