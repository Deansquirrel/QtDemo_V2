#ifndef ANDROIDMAP_H
#define ANDROIDMAP_H

#include <QObject>
#include <QThread>
#include <QDebug>

#include "src/Plugin/AMap/AMapLocation.h"
#include "src/Plugin/AMap/AMapPoiSearch.h"
#include "src/Plugin/AMap/AMapNavi.h"

class AndroidMap : public QObject
{
    Q_OBJECT
public:
    explicit AndroidMap(QObject *parent = nullptr);

    Q_INVOKABLE void subTest();

    Q_INVOKABLE void location();

    Q_INVOKABLE void getPoiInfo(QString address);

    Q_INVOKABLE void startNaviPage(QString address);

signals:
    void signalShowNote(QString msg);

    //启动查询POI线程
    void startPoiSearch(QString address);

public slots:

private slots:
    void handleUpdateLocation(double latitude,double longitude);
    void handleLocationErr(QString errmsg);

    void handlePoiSearchSuccess(QString poiId,QString poiTitle,double latitude,double longitude,int errCode);
    void handlePoiSearchErr(QString errmsg);

};

#endif // ANDROIDMAP_H
