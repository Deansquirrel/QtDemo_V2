#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

#ifdef Q_OS_ANDROID
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#endif

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

    Q_INVOKABLE void subTest();

signals:

public slots:
};

#endif // TEST_H
