#ifndef CONFIG_H
#define CONFIG_H

#include <qglobal.h>
#include <QMap>
#include <joystickbuttons.h>

class Config
{

private:
    //Singleton private constructor and instance
    Config();
    static Config* instance;

public:
    static Config* Instance();

    uint port;

    QMap<Joystick::Buttons,Qt::Key> buttonToKeys;
};

#endif // SERVER_H
