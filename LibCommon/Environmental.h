#ifndef ENVIRONMENTAL_H
#define ENVIRONMENTAL_H

#include <QObject>
#include <QNetworkInterface>
#include <QHostInfo>
#include <QString>
#include <QList>

class Environmental : public QObject
{
    Q_OBJECT
public:
    explicit Environmental(QObject *parent = 0);

    QString getLocalMac();
    QString getLocalHostName();
    QString getLocalIP();

signals:

public slots:
};

#endif // ENVIRONMENTAL_H
