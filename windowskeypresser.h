#ifndef WINDOWSKEYPRESSER_H
#define WINDOWSKEYPRESSER_H

#include "qglobal.h"
#include "keypresser.h"

#ifdef Q_OS_WIN

class WindowsKeyPresser : public KeyPresser
{
public:
    WindowsKeyPresser();
    void sendKeyPress(Qt::Key,bool);
};

#endif //Q_WS_WIN

#endif // WINDOWSKEYPRESSER_H
