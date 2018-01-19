#ifndef SYSBUS_H
#define SYSBUS_H

#include <QObject>
#include <QJsonObject>

class SysBus : public QObject
{
    Q_OBJECT
public:
    explicit SysBus(QObject *parent = nullptr);

signals:
    Q_INVOKABLE void signalShowSysNote(QString msg,int time = 3000);
    Q_INVOKABLE void signalLoadQml(QString billKey,QJsonObject initData={});

    Q_INVOKABLE void signalLockScreen(QString msg="");
    Q_INVOKABLE void signalUnlockScreen();

public slots:
};

#endif // SYSBUS_H
