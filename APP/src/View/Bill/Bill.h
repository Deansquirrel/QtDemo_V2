#ifndef BILL_H
#define BILL_H

#include <QObject>
#include <QJsonObject>
#include <QDebug>

class Bill : public QObject
{
    Q_OBJECT
public:
    explicit Bill(QObject *parent = nullptr);

    Q_INVOKABLE void pushQml(QString billKey, QJsonObject initData = {});
    Q_INVOKABLE void popQml();

signals:
    void signalPushQml(QString url,QJsonObject initData);
    void signalPop();

    void signalShowError(QString msg);

public slots:

private:
    /**
     * @brief _billUrlData 单据信息 Key/QML路径
     */
    QMap<QString,QString> _billUrlData;
};

#endif // BILL_H
