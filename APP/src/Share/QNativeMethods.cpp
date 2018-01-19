#include "QNativeMethods.h"

QNativeMethods::QNativeMethods(QObject *parent) : QObject(parent)
{

}

void QNativeMethods::registerNativeMethods()
{
#ifdef Q_OS_ANDROID
    QAndroidJniEnvironment env;
    JNINativeMethod methods[]{
        {"subTest","()V",(void*)subTest}
    };
    qInfo()<<sizeof(methods) / sizeof(methods[0]);

    const char* classname = "com/yuansong/test/NativeMethodCalledByQt";
    jclass clazz;
    QAndroidJniObject javaClass(classname);
    clazz = env->GetObjectClass(javaClass.object<jobject>());
    if(clazz){
        qInfo()<<"clazz true";
        jint ret = env->RegisterNatives(clazz,
                                        methods,
                                        sizeof(methods) / sizeof(methods[0]));
        qInfo()<<ret;
    }
    else{
        qInfo()<<"clazz false";
    }

    if(env->ExceptionCheck()){
        env->ExceptionClear();
    }
#endif

}

void QNativeMethods::subTest()
{
    qInfo()<<"C++ subTest";
}
