#ifndef BTNCONFIGDIALOG_H
#define BTNCONFIGDIALOG_H

#include <QDialog>
#include <QMap>
#include <QKeySequenceEdit>

#include "joystickbuttons.h"

namespace Ui {
class BtnConfigDialog;
}

class BtnConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BtnConfigDialog(QWidget *parent = 0);
    ~BtnConfigDialog();

private:
    Ui::BtnConfigDialog *ui;
    QMap<Joystick::Buttons,QKeySequenceEdit*> map;

private slots:
    void keySequencePress();
    void on_buttonBox_accepted();
};

#endif // BTNCONFIGDIALOG_H
