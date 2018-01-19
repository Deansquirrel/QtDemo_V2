#include "AMapPoiSearchJavaHandle.h"

bool AMapPoiSearchJavaHandle::_isNativeMethodsRegister = false;
QDateTime AMapPoiSearchJavaHandle::_upateTime = QDateTime::currentDateTime();
QString AMapPoiSearchJavaHandle::_poiId = "";
QString AMapPoiSearchJavaHandle::_poiTitle = "";
double AMapPoiSearchJavaHandle::_latitude = 0;
double AMapPoiSearchJavaHandle::_longitude = 0;
int AMapPoiSearchJavaHandle::_errCode = -1;
bool AMapPoiSearchJavaHandle::_isValid = false;

AMapPoiSearchJavaHandle::AMapPoiSearchJavaHandle(QObject *parent) : QObject(parent)
{

}

#ifdef Q_OS_ANDROID
void AMapPoiSearchJavaHandle::startPoiSearch(QString address) throw(QString)
{
    QAndroidJniEnvironment env;
    QString errMsg = "";
    if(!_isNativeMethodsRegister){
        //Native方法未成功注册;
        try{
            registerNativeMethods();
        }catch(QString errMsg){
            throw errMsg;
        }
    }

    QAndroidJniObject context = QtAndroid::androidContext();
    jobject jcontext = context.object();

    QAndroidJniObject locationObj(JAR_AMAP_POISEARCH,"(Landroid/content/Context;)V", jcontext);

    if(!locationObj.isValid()){
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        errMsg = "JNI 类型创建失败！【" + QString(JAR_AMAP_POISEARCH) +  "】";
        qWarning()<<errMsg;
        throw errMsg;
    }

    QAndroidJniObject jaddress = QAndroidJniObject::fromString(address);

    locationObj.callMethod<void>(JAR_AMAP_POISEARCH_SEARCHPOI,"(Ljava/lang/String;)V",jaddress.object<jstring>());

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        errMsg = "JNI 调用时发生异常！【" + QString(JAR_AMAP_POISEARCH) + "/" + QString(JAR_AMAP_POISEARCH_SEARCHPOI) + "】";
        qWarning()<<errMsg;
        throw errMsg;
    }
}
#endif

#ifdef Q_OS_ANDROID
void AMapPoiSearchJavaHandle::registerNativeMethods() throw(QString)
{
    QAndroidJniEnvironment env;
    QString errMsg = "";
    JNINativeMethod methods[]{
        {"handleGetPoiInfo","(Ljava/lang/String;Ljava/lang/String;DDIZ)V",(void*)handleGetPoiInfo}
    };

    QAndroidJniObject context = QtAndroid::androidContext();
    jobject jcontext = context.object();

    QAndroidJniObject javaClass(JAR_AMAP_POISEARCH,"(Landroid/content/Context;)V", jcontext);

    if(!javaClass.isValid()){
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        errMsg = "未能成功创建 javaClasss 【" + QString(JAR_AMAP_POISEARCH) + "】";
        qWarning()<<errMsg;
        throw errMsg;
    }

    jclass clazz;
    clazz = env->GetObjectClass(javaClass.object<jobject>());
    if(!clazz){
        //创建clazz时发生异常
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        errMsg = "未找到类 " + QString(JAR_AMAP_POISEARCH);
        qWarning()<<errMsg;
        throw errMsg;
    }

    jint ret = env->RegisterNatives(clazz,
                                    methods,
                                    sizeof(methods) / sizeof(methods[0]));

    if(ret < 0){
        //注册时遇到异常
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        errMsg = "注册 " + QString(JAR_AMAP_POISEARCH) + " 时遇到问题";
        qWarning()<<errMsg;
        throw errMsg;
    }
    else{
        //注册成功
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        _isNativeMethodsRegister = true;
    }

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        errMsg = "Native方法注册成功，但存在未知异常";
        qWarning()<<errMsg;
        throw errMsg;
    }
}
#endif

#ifdef Q_OS_ANDROID
void AMapPoiSearchJavaHandle::handleGetPoiInfo(JNIEnv *env, jobject *thiz, jstring poiId, jstring poiTitle, jdouble latitude, jdouble longitude, jint errCode,jboolean isValid)
{
    Q_UNUSED(env);
    Q_UNUSED(thiz);
    _upateTime = QDateTime::currentDateTime();
    QAndroidJniObject jniPoiId("java/lang/String", "(Ljava/lang/String;)V", poiId);
    _poiId = jniPoiId.toString();
    QAndroidJniObject jniPoiTitle("java/lang/String", "(Ljava/lang/String;)V", poiTitle);
    _poiTitle = jniPoiTitle.toString();
    _latitude = latitude;
    _longitude = longitude;
    _errCode = errCode;
    _isValid = isValid;
}
#endif

QDateTime AMapPoiSearchJavaHandle::upateTime()
{
    return _upateTime;
}

QString AMapPoiSearchJavaHandle::getPoiId()
{
    return _poiId;
}

QString AMapPoiSearchJavaHandle::getPoiTitle()
{
    return _poiTitle;
}

double AMapPoiSearchJavaHandle::getLatitude()
{
    return _latitude;
}

double AMapPoiSearchJavaHandle::getLongitude()
{
    return _longitude;
}

int AMapPoiSearchJavaHandle::getErrCode()
{
    return _errCode;
}

bool AMapPoiSearchJavaHandle::getIsValid()
{
    return _isValid;
}
