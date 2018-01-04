#include "windowskeypresser.h"
#include "qglobal.h"

#ifdef Q_OS_WIN

#include "windows.h"
#include <QKeyEvent>


WindowsKeyPresser::WindowsKeyPresser()
{

}

void WindowsKeyPresser::sendKeyPress(Qt::Key key, bool press)
{
    UINT inputCant = 1;
    INPUT input;

    input.type = INPUT_KEYBOARD;

}

#endif //Q_OS_WIN
