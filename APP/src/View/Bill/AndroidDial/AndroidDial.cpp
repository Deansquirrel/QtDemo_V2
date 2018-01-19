#include "AndroidDial.h"

AndroidDial::AndroidDial(QObject *parent) : QObject(parent)
{

}

QStringList AndroidDial::getPhoneList()
{
    QStringList result;
    result.append("1212121212");
    result.append("1234");
    result.append("5c78");
    result.append("131b131313");
    result.append("234a3423");
    result.append("3453535345");
    result.append("345b53a345");
    return result;
}

void AndroidDial::dialPhone(QString phone)
{
#ifdef Q_OS_ANDROID
    LibAndroid libAndroid;
    try{
        libAndroid.dialPhone(phone);
    }
    catch(QString msg){
        emit this->signalShowErr(msg);
    }
#else
    QString msg = "非安卓环境，无法使用拨号功能。（" + phone +"）";
    qWarning()<<msg;
    emit this->signalShowErr(msg);
#endif
}
