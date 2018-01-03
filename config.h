#ifndef CONFIG_H
#define CONFIG_H

#include <qglobal.h>
#include <QMap>
#include <joystickbuttons.h>
#include <QXmlStreamReader>

class Config
{

private:
    //Singleton private constructor and instance
    Config();
    static Config* instance;

    void setDefaults();
    void readConfigXml();
    void readKeyMappings(QXmlStreamReader*);

public:
    static Config* Instance();

    uint port;

    QMap<Joystick::Buttons,Qt::Key> buttonToKeys;
};

#endif // SERVER_H
