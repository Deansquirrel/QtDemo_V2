#include "AMapLocationJavaHandle.h"

bool AMapLocationJavaHandle::_isNativeMethodsRegister = false;
QDateTime AMapLocationJavaHandle::_upateTime = QDateTime::currentDateTime();
double AMapLocationJavaHandle::_latitude = 0;
double AMapLocationJavaHandle::_longitude = 0;

AMapLocationJavaHandle::AMapLocationJavaHandle(QObject *parent) : QObject(parent)
{

}

#ifdef Q_OS_ANDROID
void AMapLocationJavaHandle::startLocation(int timeout) throw(QString)
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

    QAndroidJniObject locationObj(JAR_AMAP_LOCATION,"(Landroid/content/Context;)V", jcontext);

    if(!locationObj.isValid()){
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        errMsg = "JNI 类型创建失败！【" + QString(JAR_AMAP_LOCATION) +  "】";
        qWarning()<<errMsg;
        throw errMsg;
    }

    jint jtimeout = timeout;

    locationObj.callMethod<void>(JAR_AMAP_LOCATIONMETHOD,"(I)V",jtimeout);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        errMsg = "JNI 调用时发生异常！【" + QString(JAR_AMAP_LOCATION) + "/" + QString(JAR_AMAP_LOCATIONMETHOD) + "】";
        qWarning()<<errMsg;
        throw errMsg;
    }
}
#endif

#ifdef Q_OS_ANDROID
void AMapLocationJavaHandle::registerNativeMethods() throw(QString)
{
    QAndroidJniEnvironment env;
    QString errMsg = "";
    JNINativeMethod methods[]{
        {"handleGetLocation","(DD)V",(void*)handleGetLocation},
    };

    QAndroidJniObject context = QtAndroid::androidContext();
    jobject jcontext = context.object();

    QAndroidJniObject javaClass(JAR_AMAP_LOCATION,"(Landroid/content/Context;)V", jcontext);

    if(!javaClass.isValid()){
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        errMsg = "注册Native方法时发生异常，未能成功创建 javaClasss 【" + QString(JAR_AMAP_LOCATION) + "】";
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
        errMsg = "未找到类 " + QString(JAR_AMAP_LOCATION);
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
        errMsg = "注册 " + QString(JAR_AMAP_LOCATION) + " 时遇到问题";
        qWarning()<<errMsg;
        throw errMsg;
    }
    else{
        //注册成功
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
void AMapLocationJavaHandle::handleGetLocation(JNIEnv *env, jobject *thiz, jdouble latitude, jdouble longitude)
{
    Q_UNUSED(env);
    Q_UNUSED(thiz);
    double qLatitude = latitude;
    double qLongitude = longitude;
    _latitude = qLatitude;
    _longitude = qLongitude;
    _upateTime = QDateTime::currentDateTime();
}
#endif

double AMapLocationJavaHandle::latitude()
{
    return _latitude;
}

double AMapLocationJavaHandle::longitude()
{
    return _longitude;
}

QDateTime AMapLocationJavaHandle::upateTime()
{
    return _upateTime;
}
