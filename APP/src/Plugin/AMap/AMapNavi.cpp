#include "AMapNavi.h"

AMapNavi::AMapNavi(QObject *parent) : QObject(parent)
{

}

void AMapNavi::showRouteActivity(QString poiId, QString poiTitle, double latitude, double longitude)
{
#ifndef Q_OS_ANDROID
    _errMsg = "非安卓环境，无法调用";
    _isError = true;
    emit this->naviErr(_errMsg);
#else
    AMapNaviJavaHandle aMapNaviJavaHandle;
    try{
        aMapNaviJavaHandle.showRouteActivity(poiId,poiTitle,latitude,longitude);
    }catch(QString errMsg){
        _errMsg = errMsg;
        _isError = true;
        emit this->naviErr(_errMsg);
        return;
    }

#endif
}
