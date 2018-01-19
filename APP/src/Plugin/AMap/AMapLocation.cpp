#include "AMapLocation.h"

AMapLocation::AMapLocation(QObject *parent) : QObject(parent)
{

}

void AMapLocation::startLocation()
{
#ifndef Q_OS_ANDROID
    _errMsg = "非安卓环境，无法调用";
    _isLocationErr = true;
    emit this->locationErr(_errMsg);
#else
    QDateTime startTime = QDateTime::currentDateTime();
    QDateTime outTime = startTime.addMSecs(_timeout);
    AMapLocationJavaHandle aMapLocationJavaHandle;
    try{
        aMapLocationJavaHandle.startLocation(_timeout);
    }catch(QString errMsg){
        _errMsg = errMsg;
        _isLocationErr = true;
        emit this->locationErr(_errMsg);
        return;
    }
    QDateTime updateTime = startTime;
    do{
        updateTime = aMapLocationJavaHandle.upateTime();
        if(updateTime > startTime){
            _latitude = aMapLocationJavaHandle.latitude();
            _longitude = aMapLocationJavaHandle.longitude();
            _upateTime = QDateTime::currentDateTime();
            emit this->locationUpdated(aMapLocationJavaHandle.latitude(),aMapLocationJavaHandle.longitude());
            break;
        }
        if(QDateTime::currentDateTime() > outTime){
            _errMsg = "定位超时";
            _isLocationErr = true;
            emit this->locationErr(_errMsg);
            break;
        }
        QThread::msleep(_interval);
    }while(true);
#endif
}

QString AMapLocation::errMsg() const
{
    return _errMsg;
}

bool AMapLocation::isLocationErr() const
{
    return _isLocationErr;
}

int AMapLocation::interval() const
{
    return _interval;
}

void AMapLocation::setInterval(int interval)
{
    _interval = interval;
}

int AMapLocation::timeout() const
{
    return _timeout;
}

void AMapLocation::setTimeout(int timeout)
{
    _timeout = timeout;
}

double AMapLocation::latitude() const
{
    return _latitude;
}

double AMapLocation::longitude() const
{
    return _longitude;
}

QDateTime AMapLocation::upateTime() const
{
    return _upateTime;
}
