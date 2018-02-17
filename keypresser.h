#ifndef KEYPRESSER_H
#define KEYPRESSER_H

#include <Qt>

class KeyPresser
{
protected:
    KeyPresser();
public:
    void virtual sendKeyPress(Qt::Key,bool press) = 0;
};

#endif // KEYPRESSER_H
