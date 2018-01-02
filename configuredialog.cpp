#include "configuredialog.h"
#include "ui_configuredialog.h"

#include <QMessageBox>
#include <config.h>
#include <server.h>

ConfigureDialog::ConfigureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigureDialog)
{
    ui->setupUi(this);

    ui->linePort->setText(QString::number(Config::Instance()->port,10));
    ui->radioTcp->setChecked(true);
}

ConfigureDialog::~ConfigureDialog()
{
    delete ui;
}

void ConfigureDialog::on_buttonBox_accepted()
{
    QString error = validateInput();

    if(error.isEmpty()){
        Server::Instance()->port = ui->linePort->text().toUInt(nullptr,10);

        this->close();
    }
    else{
        QMessageBox box;

        box.setText("Invalid Input.");
        box.setInformativeText(error);
        box.setIcon(QMessageBox::Critical);

        box.exec();
    }
}

void ConfigureDialog::on_buttonBox_rejected()
{

}

void ConfigureDialog::accept()
{
    //Hago que no haga nada para que no salga
    return;
}

QString ConfigureDialog::validateInput()
{
    if(ui->radioUdp->isChecked())
        return "Not supported yet.";

    if(ui->linePort->text().isEmpty()){
        return "Port field empty";
    }

    bool res;
    ui->linePort->text().toUInt(&res,10);

    if(res)
        return QString("");
    else{
        return "Port must be a number";
    }
}
