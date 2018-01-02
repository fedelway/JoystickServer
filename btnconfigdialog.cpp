#include "btnconfigdialog.h"
#include "ui_btnconfigdialog.h"

#include <config.h>

BtnConfigDialog::BtnConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BtnConfigDialog)
{
    ui->setupUi(this);

    map.insert(Joystick::BTN_UP,ui->upLineEdit);
    map.insert(Joystick::BTN_DOWN,ui->downLineEdit);
    map.insert(Joystick::BTN_LEFT,ui->leftLineEdit);
    map.insert(Joystick::BTN_RIGHT,ui->rightLineEdit);
    map.insert(Joystick::BTN_X,ui->xLineEdit);
    map.insert(Joystick::BTN_SQUARE,ui->sqrLineEdit);
    map.insert(Joystick::BTN_TRIANGLE,ui->triangleLineEdit);
    map.insert(Joystick::BTN_CIRCLE,ui->oLineEdit);
    map.insert(Joystick::BTN_R1,ui->r1LineEdit);
    map.insert(Joystick::BTN_R2,ui->r2LineEdit);
    map.insert(Joystick::BTN_R3,ui->r3LineEdit);
    map.insert(Joystick::BTN_L1,ui->l1LineEdit);
    map.insert(Joystick::BTN_L2,ui->l2LineEdit);
    map.insert(Joystick::BTN_L3,ui->l3LineEdit);
    map.insert(Joystick::BTN_START,ui->startLineEdit);
    map.insert(Joystick::BTN_SELECT,ui->selectLineEdit);

    QMap<Joystick::Buttons,Qt::Key>::iterator i;
    for(i=Config::Instance()->buttonToKeys.begin();
        i!=Config::Instance()->buttonToKeys.end();
        i++())
    {
        map.value(i.key())->setText(QKeySequence(i.value()).toString());
    }

}

BtnConfigDialog::~BtnConfigDialog()
{
    delete ui;
}

void BtnConfigDialog::on_buttonBox_accepted()
{
    QMap<Joystick::Buttons,QLineEdit*>::iterator i;
    for(i=map.begin();i!=map.end();i++() )
    {

    }
}

void BtnConfigDialog::on_buttonBox_rejected()
{
    return;
}
