#include "Menu.h"

Menu::Menu(QObject *parent) : QObject(parent)
{

}

QList<QVariant> Menu::getMenuModel()
{
    QList<QVariant> result;
        QJsonObject json;
        QJsonObject initData = {};

        json.insert("showName","Test");
        json.insert("billKey","Test");
        clearJson(initData);
        json.insert("initData",initData);
        result.append(json);

        json.insert("showName","QMLCom");
        json.insert("billKey","QMLCom");
        clearJson(initData);
        json.insert("initData",initData);
        result.append(json);

        json.insert("showName","CryptoInQt（5位）");
        json.insert("billKey","CryptoInQt");
        clearJson(initData);
        json.insert("initData",initData);
        result.append(json);

        json.insert("showName","调用高德地图SDK");
        json.insert("billKey","AndroidMap");
        clearJson(initData);
        json.insert("initData",initData);
        result.append(json);

        json.insert("showName","调用安卓拨号");
        json.insert("billKey","AndroidDial");
        clearJson(initData);
        json.insert("initData",initData);
        result.append(json);

        return result;
}

void Menu::clearJson(QJsonObject &json)
{
    foreach (QString key, json.keys()) {
        json.remove(key);
    }
}
