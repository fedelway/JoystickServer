#include "config.h"

#include <QFile>
#include <QKeySequence>

Config* Config::instance;

Config::Config()
{
    port = 1060;

    this->setDefaults();
}

Config* Config::Instance()
{
    if(instance == nullptr){
        instance = new Config();
    }

    return instance;
}

void Config::setDefaults()
{
    buttonToKeys.insert(Joystick::BTN_UP,Qt::Key_W);
    buttonToKeys.insert(Joystick::BTN_DOWN,Qt::Key_S);
    buttonToKeys.insert(Joystick::BTN_LEFT,Qt::Key_A);
    buttonToKeys.insert(Joystick::BTN_RIGHT,Qt::Key_D);
    buttonToKeys.insert(Joystick::BTN_X,Qt::Key_K);
    buttonToKeys.insert(Joystick::BTN_SQUARE,Qt::Key_J);
    buttonToKeys.insert(Joystick::BTN_TRIANGLE,Qt::Key_I);
    buttonToKeys.insert(Joystick::BTN_CIRCLE,Qt::Key_L);
    buttonToKeys.insert(Joystick::BTN_R1,Qt::Key_O);
    buttonToKeys.insert(Joystick::BTN_R2,Qt::Key_E);
    buttonToKeys.insert(Joystick::BTN_R3,Qt::Key_X);
    buttonToKeys.insert(Joystick::BTN_L1,Qt::Key_U);
    buttonToKeys.insert(Joystick::BTN_L2,Qt::Key_Q);
    buttonToKeys.insert(Joystick::BTN_L3,Qt::Key_Z);
    buttonToKeys.insert(Joystick::BTN_START,Qt::Key_Enter);
    buttonToKeys.insert(Joystick::BTN_SELECT,Qt::Key_Shift);
}

void Config::readConfigXml()
{
    const QString fileName = "settings.xml";

    QFile xmlFile(fileName);

    if(!xmlFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        //No pudo abrir el archivo xml
        return;
    }

    QXmlStreamReader reader;
    reader.setDevice(&xmlFile);

    while(!reader.atEnd() && !reader.hasError())
    {
        QXmlStreamReader::TokenType token = reader.readNext();
        //If token is just StartDocument - go to next
        if(token == QXmlStreamReader::StartDocument) {
                continue;
        }
        //If token is StartElement - read it
        if(token == QXmlStreamReader::StartElement) {
            //If it is keyMappings continue
            if(reader.name() == "keyMappings")
            {
                readKeyMappings(&reader);
            }
        }
    }
}

void Config::readKeyMappings(QXmlStreamReader* reader)
{
    QXmlStreamReader::TokenType token = reader->readNext();

    while( !(token == QXmlStreamReader::EndElement && reader->name() == "keyMappings") )
    {
        if(token == QXmlStreamReader::StartElement)
        {
            int btn = Joystick::GetBtnFromString(reader->name().toString());

            if(btn != 0)
            {
                QKeySequence seq(reader->readElementText());
                buttonToKeys.insert((Joystick::Buttons)btn,(Qt::Key)seq.count());
            }
        }

        reader->readNext();
    }
}
