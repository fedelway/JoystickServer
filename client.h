#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QAbstractSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QAbstractSocket* socket, QObject *parent = nullptr);
    ~Client();

private:
    QAbstractSocket* socket;

signals:

public slots:

private slots:
    void dataArrived();
};

#endif // CLIENT_H
