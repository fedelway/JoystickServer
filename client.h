#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QAbstractSocket>
#include <keypresser.h>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QAbstractSocket* socket, QObject *parent = nullptr);
    ~Client();

private:
    QAbstractSocket* socket;
    KeyPresser* presser;

signals:

public slots:

private slots:
    void dataArrived();
};

#endif // CLIENT_H
