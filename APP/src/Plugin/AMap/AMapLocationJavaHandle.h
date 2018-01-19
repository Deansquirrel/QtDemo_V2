#ifndef AMAPLOCATIONJAVAHANDLE_H
#define AMAPLOCATIONJAVAHANDLE_H

#include <QObject>
#include <QDebug>
#include <QDateTime>

#ifdef Q_OS_ANDROID
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#endif

class AMapLocationJavaHandle : public QObject
{
    Q_OBJECT
public:
    explicit AMapLocationJavaHandle(QObject *parent = nullptr);

#ifdef Q_OS_ANDROID
    //启动定位
    void startLocation(int timeout) throw(QString);
#endif

#ifdef Q_OS_ANDROID
    //Native方法注册
    void registerNativeMethods() throw(QString);
#endif

#ifdef Q_OS_ANDROID
    //高德定位成功回调接口
    static void handleGetLocation(JNIEnv *env,jobject *thiz,jdouble latitude,jdouble longitude);
#endif

    static double latitude();

    static double longitude();

    static QDateTime upateTime();

public slots:

private:
    //Native方法是否成功注册
    static bool _isNativeMethodsRegister;
    //位置信息更新时间
    static QDateTime _upateTime;
    //纬度
    static double _latitude;
    //经度
    static double _longitude;

    const char* JAR_AMAP_LOCATION = "com/yuansong/amap/YLocation";
    const char* JAR_AMAP_LOCATIONMETHOD = "location";
};

#endif // AMAPLOCATIONJAVAHANDLE_H
