#ifndef AMAPPOISEARCHJAVAHANDLE_H
#define AMAPPOISEARCHJAVAHANDLE_H

#include <QObject>
#include <QDebug>
#include <QDateTime>

#ifdef Q_OS_ANDROID
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#endif

class AMapPoiSearchJavaHandle : public QObject
{
    Q_OBJECT
public:
    explicit AMapPoiSearchJavaHandle(QObject *parent = nullptr);

#ifdef Q_OS_ANDROID
    //开始查找POI
    void startPoiSearch(QString address) throw(QString);
#endif

#ifdef Q_OS_ANDROID
    //Native方法注册
    void registerNativeMethods() throw(QString);
#endif

#ifdef Q_OS_ANDROID
    //查找POI成功回调接口
    static void handleGetPoiInfo(JNIEnv *env,jobject *thiz,jstring poiId,jstring poiTitle,jdouble latitude,jdouble longitude,jint errCode,jboolean isValid);
#endif

    static QDateTime upateTime();

    static QString getPoiId();

    static QString getPoiTitle();

    static double getLatitude();

    static double getLongitude();

    static int getErrCode();

    static bool getIsValid();

signals:

public slots:

private:
    //Native方法是否成功注册
    static bool _isNativeMethodsRegister;
    //POI信息更新时间
    static QDateTime _upateTime;
    //PoiId
    static QString _poiId;
    //Poi名称
    static QString _poiTitle;
    //纬度
    static double _latitude;
    //经度
    static double _longitude;
    //错误编码
    static int _errCode;
    //POI信息是否有效
    static bool _isValid;

    const char* JAR_AMAP_POISEARCH = "com/yuansong/amap/YPoiSearch";
    const char* JAR_AMAP_POISEARCH_SEARCHPOI = "searchPoi";
};

#endif // AMAPPOISEARCHJAVAHANDLE_H
