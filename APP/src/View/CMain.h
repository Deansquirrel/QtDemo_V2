#ifndef CMAIN_H
#define CMAIN_H

#include <QObject>
#include <QMap>
#include <QJsonObject>
#include <QDebug>
#include <QThread>

class CMain : public QObject
{
    Q_OBJECT
public:
    explicit CMain(QObject *parent = nullptr);

    Q_INVOKABLE void loadQml(QString billKey = "Boot",QJsonObject initData = {});

signals:
    void signalLoadQml(QString billUrl,QJsonObject billData);

    void signalShowNote(QString msg);

public slots:

private slots:

private:
    /**
     * @brief _billUrlData 单据信息 Key/QML路径
     */
    QMap<QString,QString> _billUrlData;
};

#endif // CMAIN_H
