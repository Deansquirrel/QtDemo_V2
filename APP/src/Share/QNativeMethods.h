#ifndef QNATIVEMETHODS_H
#define QNATIVEMETHODS_H

#include <QObject>
#include <QDebug>

#ifdef Q_OS_ANDROID
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#endif

class QNativeMethods : public QObject
{
    Q_OBJECT
public:
    explicit QNativeMethods(QObject *parent = nullptr);

    void registerNativeMethods();

    static void subTest();

signals:

public slots:
};

#endif // QNATIVEMETHODS_H
