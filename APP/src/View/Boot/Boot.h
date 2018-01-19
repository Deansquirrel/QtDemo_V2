#ifndef BOOT_H
#define BOOT_H

#include <QObject>
#include <QQmlEngine>

#include "src/Data/DataCache.h"
#include "src/Data/DataGlobal.h"

#include "src/View/Bill/Bill.h"
#include "src/View/Bill/Menu/Menu.h"
#include "src/View/Bill/AndroidDial/AndroidDial.h"
#include "src/View/Bill/AndroidMap/AndroidMap.h"
#include "src/View/Bill/CryptoInQt/CryptoInQt.h"
#include "src/View/Bill/QMLCom/QMLCom.h"

#include "src/View/Bill/Test/Test.h"

#include "LibLogger.h"

class Boot : public QObject
{
    Q_OBJECT
public:
    explicit Boot(QObject *parent = nullptr);

signals:
    void signalBootFinished(QString msg = "");
    void signalBootErr(QString msg);

public slots:
    void handleBoot();

private:
    /**
     * @brief registerType 注册QML类
     */
    void registerType();
};

#endif // BOOT_H
