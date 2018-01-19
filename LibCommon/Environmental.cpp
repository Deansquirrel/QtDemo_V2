#include "Environmental.h"

Environmental::Environmental(QObject *parent) : QObject(parent)
{

}

QString Environmental::getLocalMac()
{
    QString mac ="";
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();
    foreach(QNetworkInterface ni,nets)
    {
        if (ni.name().startsWith("ethernet")) {
            mac = ni.hardwareAddress();
            break;
        }
    }
    return mac.replace(":", "");
}

QString Environmental::getLocalHostName()
{
    QString machineName = QHostInfo::localHostName();
    return machineName;
}

QString Environmental::getLocalIP()
{
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    return ipAddress;
}
