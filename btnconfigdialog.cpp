#include "btnconfigdialog.h"
#include "ui_btnconfigdialog.h"

#include <QDebug>
#include <config.h>

BtnConfigDialog::BtnConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BtnConfigDialog)
{
    ui->setupUi(this);

    //Map of buttons to ui controls
    map.insert(Joystick::BTN_UP,ui->upkeySequenceEdit);
    map.insert(Joystick::BTN_DOWN,ui->downkeySequenceEdit);
    map.insert(Joystick::BTN_LEFT,ui->leftkeySequenceEdit);
    map.insert(Joystick::BTN_RIGHT,ui->rightkeySequenceEdit);
    map.insert(Joystick::BTN_X,ui->xkeySequenceEdit);
    map.insert(Joystick::BTN_SQUARE,ui->sqrkeySequenceEdit);
    map.insert(Joystick::BTN_TRIANGLE,ui->trianglekeySequenceEdit);
    map.insert(Joystick::BTN_CIRCLE,ui->circlekeySequenceEdit);
    map.insert(Joystick::BTN_R1,ui->r1keySequenceEdit);
    map.insert(Joystick::BTN_R2,ui->r2keySequenceEdit);
    map.insert(Joystick::BTN_R3,ui->r3keySequenceEdit);
    map.insert(Joystick::BTN_L1,ui->l1keySequenceEdit);
    map.insert(Joystick::BTN_L2,ui->l2keySequenceEdit);
    map.insert(Joystick::BTN_L3,ui->l3keySequenceEdit);
    map.insert(Joystick::BTN_SELECT,ui->selectkeySequenceEdit);
    map.insert(Joystick::BTN_START,ui->startkeySequenceEdit);

    //connect every signal to the same slot
    connect(ui->upkeySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->downkeySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->leftkeySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->rightkeySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->xkeySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->sqrkeySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->trianglekeySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->circlekeySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->r1keySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->r2keySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->r3keySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->l1keySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->l2keySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->l2keySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->selectkeySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);
    connect(ui->startkeySequenceEdit,&QKeySequenceEdit::editingFinished,this,&BtnConfigDialog::keySequencePress);

    //Initialize with default values
    QMap<Joystick::Buttons,QKeySequenceEdit*>::iterator i;
    for(i=map.begin();i!=map.end();i++)
    {
        i.value()->setKeySequence(QKeySequence( Config::Instance()->buttonToKeys.value(i.key()) ));
    }

}

BtnConfigDialog::~BtnConfigDialog()
{
    delete ui;
}

void BtnConfigDialog::keySequencePress()
{
    QKeySequenceEdit* keySequenceEdit = qobject_cast<QKeySequenceEdit*>(QObject::sender());

    int key = keySequenceEdit->keySequence()[0];

    qDebug() << key;
}

void BtnConfigDialog::on_buttonBox_accepted()
{
    QMap<Joystick::Buttons,Qt::Key>::iterator i;
    for(i=Config::Instance()->buttonToKeys.begin();i!=Config::Instance()->buttonToKeys.end();i++)
    {
        Config::Instance()->buttonToKeys.insert(i.key(),(Qt::Key)map.value(i.key())->keySequence()[0]);
    }
}
