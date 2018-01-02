#ifndef BTNCONFIGDIALOG_H
#define BTNCONFIGDIALOG_H

#include <QDialog>
#include <QMap>
#include "joystickbuttons.h"
#include <QLineEdit>

namespace Ui {
class BtnConfigDialog;
}

class BtnConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BtnConfigDialog(QWidget *parent = 0);
    ~BtnConfigDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::BtnConfigDialog *ui;
    QMap<Joystick::Buttons,QLineEdit*> map;
};

#endif // BTNCONFIGDIALOG_H
