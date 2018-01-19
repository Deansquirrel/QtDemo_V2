#ifndef ANDROIDDIAL_H
#define ANDROIDDIAL_H

#include <QObject>
#include <QDebug>

#ifdef Q_OS_ANDROID
#include "LibAndroid.h"
#endif

class AndroidDial : public QObject
{
    Q_OBJECT
public:
    explicit AndroidDial(QObject *parent = nullptr);

    Q_INVOKABLE QStringList getPhoneList();

    Q_INVOKABLE void dialPhone(QString phone);

signals:
    void signalShowErr(QString msg);

public slots:
};

#endif // ANDROIDDIAL_H
