#include "LibAndroidDial.h"

LibAndroidDial::LibAndroidDial(QObject *parent) : QObject(parent)
{

}

void LibAndroidDial::handleDialPhone(QString phone, bool dial) throw(QString)
{
#ifdef Q_OS_ANDROID
    if(phone == "") throw QString("传入参数不能为空。");
    QRegExp rx("^\\+?[0-9]+");
    if(!rx.exactMatch(phone)){
        throw QString("传入参数不合法。（" + phone + "）");
    }

    QString dialStr;
    if(dial) {
        //直接打电话忽略拨号界面
        dialStr = "android.intent.action.CALL";
    }
    else{
        //打开拨号界面
        dialStr = "android.intent.action.DIAL";
    }

    QAndroidJniObject jniAction = QAndroidJniObject::fromString(dialStr);
    //构建传递到拨号 或者 直接打电话的 电话号码
    QString telStr = "tel:" + phone;
    QAndroidJniObject jniPhone = QAndroidJniObject::fromString(telStr);
    //调用静态方法构建识别码
    QAndroidJniObject jniUri    = QAndroidJniObject::callStaticObjectMethod("android/net/Uri", "parse", "(Ljava/lang/String;)Landroid/net/Uri;",jniPhone.object<jstring>());
    //构建intent类型
    QAndroidJniObject jniIntent("android/content/Intent","(Ljava/lang/String;)V", jniAction.object<jstring>());
    //调用initen方法设置数据(电话号码)
    jniIntent = jniIntent.callObjectMethod("setData","(Landroid/net/Uri;)Landroid/content/Intent;",jniUri.object<jobject>());
    //调用实际方法
    QtAndroid::startActivity(jniIntent,0);
//    QAndroidJniEnvironment env;
//    if(env->ExceptionCheck()){
//        qWarning()<<"调用安卓拨号功能时发生异常。（" + phone + "," + dial +  "）";
//        env->ExceptionDescribe();
//        env->ExceptionClear();
//    }
#else
    qWarning()<<"非安卓系统，无法使用拨号功能。（" + phone + "," + dial + "）";
#endif
}
