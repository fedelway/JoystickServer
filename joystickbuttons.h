#ifndef BUTTONSENUM_H
#define BUTTONSENUM_H

#include <QString>

namespace Joystick {

enum Buttons{
    BTN_UP = 1,
    BTN_DOWN = 2,
    BTN_LEFT = 3,
    BTN_RIGHT = 4,
    BTN_X = 5,
    BTN_SQUARE = 6,
    BTN_TRIANGLE = 7,
    BTN_CIRCLE = 8,
    BTN_R1 = 9,
    BTN_R2 = 10,
    BTN_R3 = 11,
    BTN_L1 = 12,
    BTN_L2 = 13,
    BTN_L3 = 14,
    BTN_START = 15,
    BTN_SELECT = 16
};

QString GetButtonName(Buttons b);
int GetBtnFromString(QString name);

}

#endif // BUTTONSENUM_H
