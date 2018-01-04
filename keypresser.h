#ifndef KEYPRESSER_H
#define KEYPRESSER_H

#include <Qt>

class KeyPresser
{

public:
    KeyPresser();
    void virtual sendKeyPress(Qt::Key,bool press);
}


#endif // KEYPRESSER_H
