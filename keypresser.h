#ifndef KEYPRESSER_H
#define KEYPRESSER_H

#include <Qt>

class KeyPresser
{

public:
    KeyPresser(){}
    virtual ~KeyPresser(){}
    void virtual sendKeyPress(Qt::Key,bool press) = 0;
};

#endif // KEYPRESSER_H
