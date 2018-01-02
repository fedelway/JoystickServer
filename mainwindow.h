#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <server.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnConfigure_clicked();

    void on_btnClose_clicked();

    void on_btnStartClose_clicked();

    void on_btnConfigureJoystick_clicked();

private:
    Ui::MainWindow *ui;

    void startServer();
    void stopServer();
};

#endif // MAINWINDOW_H
