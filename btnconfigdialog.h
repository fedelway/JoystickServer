#ifndef BTNCONFIGDIALOG_H
#define BTNCONFIGDIALOG_H

#include <QDialog>

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
};

#endif // BTNCONFIGDIALOG_H
