#ifndef AMAPLOCATION_H
#define AMAPLOCATION_H

#include <QObject>
#include <QDateTime>
#include <QThread>
#include <QDebug>

#include "AMapLocationJavaHandle.h"

class AMapLocation : public QObject
{
    Q_OBJECT
public:
    explicit AMapLocation(QObject *parent = nullptr);

    //纬度
    double latitude() const;
    //经度
    double longitude() const;
    //位置信息更新时间
    QDateTime upateTime() const;
    //超时时间（毫秒）
    int timeout() const;
    void setTimeout(int timeout);
    //轮询间隔时间（毫秒）
    int interval() const;
    void setInterval(int interval);

    //检查定位是否成功
    bool isLocationErr() const;
    //错误信息
    QString errMsg() const;

signals:
    //定位成功
    void locationUpdated(double latitude,double longitude);
    //发生错误
    void locationErr(QString errmsg);

public slots:
    //开始定位
    void startLocation();

private:
    double _latitude = 0;
    double _longitude = 0;
    int _timeout = 20000;
    int _interval = 500;
    bool _isLocationErr = false;
    QString _errMsg = "";
    QDateTime _upateTime = QDateTime::currentDateTime();

};

#endif // AMAPLOCATION_H
