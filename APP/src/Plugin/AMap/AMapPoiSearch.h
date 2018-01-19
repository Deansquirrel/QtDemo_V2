#ifndef AMAPPOISEARCH_H
#define AMAPPOISEARCH_H

#include <QObject>
#include <QDateTime>
#include <QThread>
#include <QDebug>

#include "AMapPoiSearchJavaHandle.h"

class AMapPoiSearch : public QObject
{
    Q_OBJECT
public:
    explicit AMapPoiSearch(QObject *parent = nullptr);

    //PoiId
    QString getPoiId() const;
    //Poi名称
    QString getPoiTitle() const;
    //纬度
    double getLatitude() const;
    //经度
    double getLongitude() const;
    //错误编码
    int getErrCode() const;

    //错误信息
    QString getErrMsg() const;
    //是否有错误
    bool getIsError() const;

    //超时时间（毫秒）
    int getTimeout() const;
    void setTimeout(int timeout);
    //轮询间隔时间（毫秒）
    int getInterval() const;
    void setInterval(int interval);

signals:
    //查找成功
    void poiSearchSuccess(QString poiId,QString poiTitle,double latitude,double longitude);
    //发生错误
    void poiSearchErr(QString msg);

public slots:
    //开始查找
    void startPoiSearch(QString address);

private:
    int _timeout = 20000;
    int _interval = 500;
    bool _isError = false;
    QString _errMsg = "";
    QDateTime _updatTime = QDateTime::currentDateTime();

    QString _poiId = "";
    QString _poiTitle = "";
    double _latitude = 0;
    double _longitude = 0;
    int _errCode = -1;
};

#endif // AMAPPOISEARCH_H
