#include "btnconfigdialog.h"
#include "ui_btnconfigdialog.h"

BtnConfigDialog::BtnConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BtnConfigDialog)
{
    ui->setupUi(this);
}

BtnConfigDialog::~BtnConfigDialog()
{
    delete ui;
}
