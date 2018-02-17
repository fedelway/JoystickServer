#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <configuredialog.h>
#include <btnconfigdialog.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnConfigure_clicked()
{
    ConfigureDialog cfgDialog(this);

    cfgDialog.exec();
}

void MainWindow::on_btnConfigureJoystick_clicked()
{
    BtnConfigDialog dialog(this);

    dialog.exec();
}

void MainWindow::on_btnClose_clicked()
{
    this->close();
}

void MainWindow::on_btnStartClose_clicked()
{
    if(!Server::Instance()->isRunning()){
        this->startServer();
    }else this->stopServer();
}

void MainWindow::startServer()
{
    QString error = Server::Instance()->startServer();

    if(!error.isEmpty())
    {
        QMessageBox errorBox;

        errorBox.setText("Error");
        errorBox.setInformativeText(error);
        errorBox.setIcon(QMessageBox::Critical);

        errorBox.exec();
    }else{
        ui->lblServerInfo->setText(Server::Instance()->serverInfo());
        ui->btnStartClose->setText("Stop Server");

        //Deshabilito el boton de configurar puerto
        ui->btnConfigure->setEnabled(false);
    }
}

void MainWindow::stopServer()
{
    Server::Instance()->stopServer();

    ui->lblServerInfo->setText("");
    ui->btnStartClose->setText("Start Server");

    //Vuelvo a habilitar el boton de configurar puerto
    ui->btnConfigure->setEnabled(true);
}
