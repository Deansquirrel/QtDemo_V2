#ifndef AMAPNAVI_H
#define AMAPNAVI_H

#include <QObject>
#include <QDebug>

#include "AMapNaviJavaHandle.h"

class AMapNavi : public QObject
{
    Q_OBJECT
public:
    explicit AMapNavi(QObject *parent = nullptr);

signals:
    void naviErr(QString errMsg);

public slots:
    //启动导航
    void showRouteActivity(QString poiId,QString poiTitle,double latitude,double longitude);

private:
    QString _errMsg = "";
    bool _isError = false;
};

#endif // AMAPNAVI_H
