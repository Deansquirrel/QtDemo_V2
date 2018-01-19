#include "AndroidMap.h"

AndroidMap::AndroidMap(QObject *parent) : QObject(parent)
{

}

void AndroidMap::subTest()
{

}

void AndroidMap::location()
{
    //    同步调用
    //    qInfo()<<"定位开始";
    //    AMapLocation aMapLocation;
    //    aMapLocation.startLocation();
    //    if(aMapLocation.isLocationErr()){
    //        qInfo()<<"定位失败";
    //        qInfo()<<aMapLocation.errMsg();
    //    }
    //    else{
    //        qInfo()<<"定位成功";
    //        qInfo()<<aMapLocation.latitude();
    //        qInfo()<<aMapLocation.longitude();
    //    }
    //    qInfo()<<"定位结束";

    //    异步调用
        QThread* qThread = new QThread();
        AMapLocation* aMapLocation = new AMapLocation();

        QObject::connect(qThread,SIGNAL(started()),aMapLocation,SLOT(startLocation()));
        QObject::connect(aMapLocation,SIGNAL(locationUpdated(double,double)),
                         this,SLOT(handleUpdateLocation(double,double)));
        QObject::connect(aMapLocation,SIGNAL(locationErr(QString)),
                         this,SLOT(handleLocationErr(QString)));
        QObject::connect(aMapLocation,SIGNAL(locationUpdated(double,double)),
                         qThread,SLOT(quit()));
        QObject::connect(aMapLocation,SIGNAL(locationErr(QString)),
                         qThread,SLOT(quit()));
        QObject::connect(qThread,SIGNAL(finished()),qThread,SLOT(deleteLater()));

        aMapLocation->moveToThread(qThread);
        qThread->start();
}

void AndroidMap::getPoiInfo(QString address)
{
    //    同步调用
    AMapPoiSearch aMapPoiSearch;
    aMapPoiSearch.startPoiSearch(address);
    if(aMapPoiSearch.getIsError()){
        emit this->signalShowNote(aMapPoiSearch.getErrMsg());
        return;
    }
    else{
        QString msg = "获取POI信息成功。";
        msg = msg + "|" + aMapPoiSearch.getPoiId();
        msg = msg + "|" + aMapPoiSearch.getPoiTitle();
        msg = msg + "|" + QString::number(aMapPoiSearch.getLatitude());
        msg = msg + "|" + QString::number(aMapPoiSearch.getLongitude());
        msg = msg + "|" + QString::number(aMapPoiSearch.getErrCode());
        emit this->signalShowNote(msg);
    }
    //异步调用
//    QThread* qThread = new QThread();
//    AMapPoiSearch* aMapPoiSearch = new AMapPoiSearch();

//    QObject::connect(this,SIGNAL(startPoiSearch(QString)),
//                     aMapPoiSearch,SLOT(startPoiSearch(QString)));
//    QObject::connect(aMapPoiSearch,SIGNAL(poiSearchSuccess(QString,QString,double,double,int)),
//                     this,SLOT(handlePoiSearchSuccess(QString,QString,double,double,int)));
//    QObject::connect(aMapPoiSearch,SIGNAL(poiSearchErr(QString)),
//                     this,SLOT(handlePoiSearchErr(QString)));
//    QObject::connect(aMapPoiSearch,SIGNAL(poiSearchSuccess(QString,QString,double,double,int)),
//                     qThread,SLOT(quit()));
//    QObject::connect(aMapPoiSearch,SIGNAL(poiSearchErr(QString)),
//                     qThread,SLOT(quit()));
//    QObject::connect(qThread,SIGNAL(finished()),qThread,SLOT(deleteLater()));

//    aMapPoiSearch->moveToThread(qThread);
//    qThread->start();

//    emit this->startPoiSearch(address);
}

void AndroidMap::startNaviPage(QString address)
{
    Q_UNUSED(address)
    //    同步调用
    AMapPoiSearch aMapPoiSearch;
    aMapPoiSearch.startPoiSearch(address);
    if(aMapPoiSearch.getIsError()){
        emit this->signalShowNote(aMapPoiSearch.getErrMsg());
        return;
    }
    else{
        QString msg = "获取POI信息成功(Navi)。";
        msg = msg + "|" + aMapPoiSearch.getPoiId();
        msg = msg + "|" + aMapPoiSearch.getPoiTitle();
        msg = msg + "|" + QString::number(aMapPoiSearch.getLatitude());
        msg = msg + "|" + QString::number(aMapPoiSearch.getLongitude());
        msg = msg + "|" + QString::number(aMapPoiSearch.getErrCode());
        qInfo()<<msg;
        AMapNavi aMapNavi;
        aMapNavi.showRouteActivity(aMapPoiSearch.getPoiId(),aMapPoiSearch.getPoiTitle(),aMapPoiSearch.getLatitude(),aMapPoiSearch.getLongitude());
    }
}

void AndroidMap::handleUpdateLocation(double latitude, double longitude)
{
    qInfo()<<"定位成功";
    qInfo()<<latitude;
    qInfo()<<longitude;
    QString msg = QString("定位成功。") + QString("latitude - ") + QString::number(latitude) + QString(";longitude - ") + QString::number(longitude);
    emit this->signalShowNote(msg);
}

void AndroidMap::handleLocationErr(QString errmsg)
{
    qInfo()<<"定位失败";
    qInfo()<<errmsg;
    emit this->signalShowNote(errmsg);
}

void AndroidMap::handlePoiSearchSuccess(QString poiId, QString poiTitle, double latitude, double longitude, int errCode)
{
    qInfo()<<poiId<<"|"<<poiTitle<<"|"<<latitude<<"|"<<longitude<<"|"<<errCode;
}

void AndroidMap::handlePoiSearchErr(QString errmsg)
{
    qInfo()<<errmsg;
}
