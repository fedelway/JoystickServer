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

QString GetButtonName(Buttons b)
{
    switch(b){
        case Buttons::BTN_UP:
            return "UP";break;
        case Buttons::BTN_DOWN:
            return "DOWN";break;
        case Buttons::BTN_LEFT:
            return "LEFT";break;
        case Buttons::BTN_RIGHT:
            return "RIGHT";break;
        case Buttons::BTN_X:
            return "X";break;
        case Buttons::BTN_SQUARE:
            return "SQUARE";break;
        case Buttons::BTN_TRIANGLE:
            return "TRIANGLE";break;
        case Buttons::BTN_CIRCLE:
            return "CIRCLE";break;
        case Buttons::BTN_R1:
            return "R1";break;
        case Buttons::BTN_R2:
            return "R2";break;
        case Buttons::BTN_R3:
            return "R3";break;
        case Buttons::BTN_L1:
            return "L1";break;
        case Buttons::BTN_L2:
            return "L2";break;
        case Buttons::BTN_L3:
            return "L3";break;
        case Buttons::BTN_SELECT:
            return "SELECT";break;
        case Buttons::BTN_START:
            return "START";break;
        default: return "";
    }
}

int GetBtnFromString(QString name)
{
    if(name=="UP")
        return Buttons::BTN_UP;
    if(name=="DOWN")
        return Buttons::BTN_DOWN;
    if(name=="LEFT")
        return Buttons::BTN_LEFT;
    if(name=="RIGHT")
        return Buttons::BTN_RIGHT;
    if(name=="X")
        return Buttons::BTN_X;
    if(name=="SQUARE")
        return Buttons::BTN_SQUARE;
    if(name=="TRIANGLE")
        return Buttons::BTN_TRIANGLE;
    if(name=="CIRCLE")
        return Buttons::BTN_CIRCLE;
    if(name=="R1")
        return Buttons::BTN_R1;
    if(name=="R2")
        return Buttons::BTN_R2;
    if(name=="R3")
        return Buttons::BTN_R3;
    if(name=="L1")
        return Buttons::BTN_L1;
    if(name=="L2")
        return Buttons::BTN_L2;
    if(name=="L3")
        return Buttons::BTN_L3;
    if(name=="SELECT")
        return Buttons::BTN_SELECT;
    if(name=="START")
        return Buttons::BTN_START;

    return 0;
}

}

#endif // BUTTONSENUM_H
