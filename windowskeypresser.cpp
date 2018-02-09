#include "windowskeypresser.h"
#include "qglobal.h"

#ifdef Q_OS_WIN

#include "windows.h"
#include <QKeyEvent>

WindowsKeyPresser::WindowsKeyPresser()
{

}

WindowsKeyPresser::~WindowsKeyPresser()
{

}

void WindowsKeyPresser::sendKeyPress(Qt::Key key, bool press)
{
    UINT inputCant = 1;
    INPUT input;

    //get keyboard data
    char Buff[120] = {0};
    GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_ILANGUAGE, (LPWSTR)Buff, sizeof(Buff));
    HKL hKeyboardLayout = ::LoadKeyboardLayout( (LPCWSTR)Buff, KLF_ACTIVATE );

    //get virtual key code
    const SHORT Vk = VkKeyScanEx(QKeySequence(key).toString()[0].toLatin1(), hKeyboardLayout);
    const UINT VKey = ::MapVirtualKey( LOBYTE( Vk ), 0 );

    input.type = INPUT_KEYBOARD;
    input.ki.wScan = VKey;

    if(press)
        input.ki.dwFlags = KEYEVENTF_SCANCODE;
    else input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;

    UINT res = SendInput(inputCant,&input,sizeof(INPUT));

    if(res<=0){
        DWORD err = GetLastError();
    }

    if(hKeyboardLayout)
        UnloadKeyboardLayout(hKeyboardLayout);
}

#endif //Q_OS_WIN
