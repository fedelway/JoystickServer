#include "config.h"

#include <QFile>
#include <QKeySequence>
#include <QMessageBox>
#include <QDir>

Config* Config::instance;

Config::Config()
{
    port = 1060;

    this->setDefaults();
    this->readConfigXml();
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
    //const QString fileName = QDir::currentPath() + "/settings.xml";
    const QString fileName = "E:/FedericoP/Desktop/settings.xml";

    QFile xmlFile(fileName);

    if(!xmlFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        this->showError("No se pudo abrir el archivo de configuración.",xmlFile.errorString());
        return;
    }

    QXmlStreamReader reader;
    reader.setDevice(&xmlFile);

    while(!reader.atEnd() && !reader.hasError())
    {
        QXmlStreamReader::TokenType token = reader.readNext();
        //If token is just StartDocument - go to next
        if(token == QXmlStreamReader::StartDocument) {
            if(reader.name() != "Joystick"){
                //this->showError("El xml no esta bien formateado.","");
                //break;
            }else continue;
        }
        //If token is StartElement - read it
        if(token == QXmlStreamReader::StartElement) {
            //If it is keyMappings continue
            if(reader.name() == "KeyMappings")
            {
                readKeyMappings(&reader);
            }
        }
    }

    xmlFile.close();
}


void Config::readKeyMappings(QXmlStreamReader* reader)
{
    QXmlStreamReader::TokenType token = reader->readNext();

    while( !(token == QXmlStreamReader::EndElement && reader->name() == "KeyMappings") && !reader->hasError() )
    {
        if(token == QXmlStreamReader::Characters)
        {
            int btn = Joystick::GetBtnFromString(reader->name().toString());

            if(btn != 0)
            {
                QKeySequence seq(reader->readElementText().toUpper());
                buttonToKeys.insert((Joystick::Buttons)btn,(Qt::Key)seq[0]);
            }
        }

        reader->readNext();
    }
}

void Config::showError(QString error, QString informative)
{
    QMessageBox box;

    box.setText(error);
    box.setInformativeText(informative);
    box.setIcon(QMessageBox::Information);
    box.exec();
}
