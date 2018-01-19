#include "AMapPoiSearch.h"

AMapPoiSearch::AMapPoiSearch(QObject *parent) : QObject(parent)
{

}

QString AMapPoiSearch::getPoiId() const
{
    return _poiId;
}

QString AMapPoiSearch::getPoiTitle() const
{
    return _poiTitle;
}

double AMapPoiSearch::getLatitude() const
{
    return _latitude;
}

double AMapPoiSearch::getLongitude() const
{
    return _longitude;
}

int AMapPoiSearch::getErrCode() const
{
    return _errCode;
}

QString AMapPoiSearch::getErrMsg() const
{
    return _errMsg;
}

bool AMapPoiSearch::getIsError() const
{
    return _isError;
}

void AMapPoiSearch::startPoiSearch(QString address)
{
#ifndef Q_OS_ANDROID
    _errMsg = "非安卓环境，无法调用";
    _isError = true;
    emit this->poiSearchErr(_errMsg);
#else
    QDateTime startTime = QDateTime::currentDateTime();
    QDateTime outTime = startTime.addMSecs(_timeout);

    AMapPoiSearchJavaHandle aMapPoiSearchJavaHandle;
    try{
        aMapPoiSearchJavaHandle.startPoiSearch(address);
    }catch(QString errMsg){
        _errMsg = errMsg;
        _isError = true;
        emit this->poiSearchErr(_errMsg);
        return;
    }


//    获取返回结果
    QDateTime updateTime = startTime;
    do{
        updateTime = aMapPoiSearchJavaHandle.upateTime();
        if(updateTime > startTime){
            _poiId = aMapPoiSearchJavaHandle.getPoiId();
            _poiTitle = aMapPoiSearchJavaHandle.getPoiTitle();
            _latitude = aMapPoiSearchJavaHandle.getLatitude();
            _longitude = aMapPoiSearchJavaHandle.getLongitude();
            _errCode = aMapPoiSearchJavaHandle.getErrCode();
            if(aMapPoiSearchJavaHandle.getIsValid()){
                emit this->poiSearchSuccess(_poiId,_poiTitle,_latitude,_longitude);
            }
            else{
                _errCode = aMapPoiSearchJavaHandle.getErrCode();
                if(_errCode == 1000){
                    _isError = true;
                    _errMsg = "未获取到有效的POI信息";
                    emit this->poiSearchErr(_errMsg);
                }
                else{
                    _isError = true;
                    _errMsg = "获取POI信息时发生异常。【errCode：" + QString::number(_errCode) + "】";
                    emit this->poiSearchErr(_errMsg);
                }
            }
            break;
        }
        if(QDateTime::currentDateTime() > outTime){
            _errMsg = "获取POI超时";
            _isError = true;
            emit this->poiSearchErr(_errMsg);
            break;
        }
        QThread::msleep(_interval);
    }while(true);
#endif
}

int AMapPoiSearch::getInterval() const
{
    return _interval;
}

void AMapPoiSearch::setInterval(int interval)
{
    _interval = interval;
}

int AMapPoiSearch::getTimeout() const
{
    return _timeout;
}

void AMapPoiSearch::setTimeout(int timeout)
{
    _timeout = timeout;
}
