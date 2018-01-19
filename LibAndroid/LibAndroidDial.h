#ifndef LIBANDROIDDIAL_H
#define LIBANDROIDDIAL_H

#include <QObject>
#include <QRegExp>
#ifdef Q_OS_ANDROID
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#endif
#include <QDebug>

class LibAndroidDial : public QObject
{
    Q_OBJECT
public:
    explicit LibAndroidDial(QObject *parent = nullptr);

    /**
     * @brief handleDialCall 拨打电话
     * @param phone 电话号码
     * @param dial 是否直接呼叫
     */
    void handleDialPhone(QString phone, bool dial = false) throw(QString);

signals:

public slots:

};

#endif // LIBANDROIDDIAL_H
