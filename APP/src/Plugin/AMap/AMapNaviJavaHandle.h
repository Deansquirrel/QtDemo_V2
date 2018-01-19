#ifndef AMAPNAVIJAVAHANDLE_H
#define AMAPNAVIJAVAHANDLE_H

#include <QObject>
#include <QDebug>

#ifdef Q_OS_ANDROID
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#endif

class AMapNaviJavaHandle : public QObject
{
    Q_OBJECT
public:
    explicit AMapNaviJavaHandle(QObject *parent = nullptr);

#ifdef Q_OS_ANDROID
    //开启导航
    void showRouteActivity(QString poiId,QString poiTitle,double latitude,double longitude) throw(QString);
#endif

signals:

public slots:

private:
    const char* JAR_AMAP_NAVI = "com/yuansong/amap/YNaviPage";
    const char* JAR_AMAP_NAVI_SHOWROUTEACTIVITY = "showRouteActivity";
};

#endif // AMAPNAVIJAVAHANDLE_H
