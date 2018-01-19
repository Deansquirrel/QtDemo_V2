#include "CryptoInQt.h"

CryptoInQt::CryptoInQt(QObject *parent) : QObject(parent)
{
    _sPlaintext = "000,003,10062,CARDSLEEP,123456";
}

void CryptoInQt::subTest()
{
    qInfo()<<"subTest";
}

QString CryptoInQt::createCode(QString sPlaintext)
{
    LibCryptoInQt libCryptoInQt;
    return libCryptoInQt.CalcDynamicDigestCode4Len5(QDateTime::currentDateTime(),sPlaintext);
}

QString CryptoInQt::checkCode(QString sPlaintext, QString code)
{
    LibCryptoInQt libCryptoInQt;
    return libCryptoInQt.VerifyDynamicDigestCode4Len5(QDateTime::currentDateTime(),sPlaintext,code);
}

QString CryptoInQt::sPlaintext() const
{
    return _sPlaintext;
}
