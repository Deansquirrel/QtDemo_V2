#include "AMapNaviJavaHandle.h"

AMapNaviJavaHandle::AMapNaviJavaHandle(QObject *parent) : QObject(parent)
{

}

#ifdef Q_OS_ANDROID
void AMapNaviJavaHandle::showRouteActivity(QString poiId, QString poiTitle, double latitude, double longitude) throw(QString)
{
    QAndroidJniEnvironment env;
    QString errMsg = "";

    QAndroidJniObject context = QtAndroid::androidContext();
    jobject jcontext = context.object();

    QAndroidJniObject locationObj(JAR_AMAP_NAVI,"(Landroid/content/Context;)V", jcontext);

    if(!locationObj.isValid()){
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        errMsg = "JNI 类型创建失败！【" + QString(JAR_AMAP_NAVI) +  "】";
        qWarning()<<errMsg;
        throw errMsg;
    }

    QAndroidJniObject jniPoiId = QAndroidJniObject::fromString(poiId);
    QAndroidJniObject jniPoiTitle = QAndroidJniObject::fromString(poiTitle);
    jdouble jlatitude = latitude;
    jdouble jlongitude = longitude;

    locationObj.callMethod<void>(JAR_AMAP_NAVI_SHOWROUTEACTIVITY,"(Ljava/lang/String;Ljava/lang/String;DD)V",jniPoiId.object<jstring>(),jniPoiTitle.object<jstring>(),jlatitude,jlongitude);

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        errMsg = "JNI 调用时发生异常！【" + QString(JAR_AMAP_NAVI) + "/" + QString(JAR_AMAP_NAVI_SHOWROUTEACTIVITY) + "】";
        qWarning()<<errMsg;
        throw errMsg;
    }

}
#endif
