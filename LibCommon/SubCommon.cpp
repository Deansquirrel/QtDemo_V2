#include "SubCommon.h"

SubCommon::SubCommon()
{

}

QString SubCommon::getMD5(QString data){
    QString result;
    QByteArray tempA, tempB;
    QCryptographicHash md(QCryptographicHash::Md5);
    tempA.append(data);
    md.addData(tempA);
    tempB = md.result();
    result.append(tempB.toHex());
    return result;
}
