#include "LibCryptoInQt.h"


LibCryptoInQt::LibCryptoInQt()
{
}

QString LibCryptoInQt::CalcDynamicDigestCode4Len5(QDateTime dValidTime, QString sPlaintext) throw(QString)
{
    if(dValidTime < QDateTime::fromString("2000-01-01","yyyy-MM-dd")){
        throw QString("时间参数无效。（" + dValidTime.toString("yyyyMMddhhmm") + "）");
    }

    QDateTime dValidTimeCheck = dValidTime.addSecs(60 * 10);

    QString sTimeStr = dValidTimeCheck.toString("yyyyMMddhhmm");

    QDateTime initDate(QDate(2000,1,1),QTime(0,0));
    QString sTimeCode = QString::number((initDate.secsTo(dValidTimeCheck) / 60) % 1000);
    this->addZero(sTimeCode,3);

    QString sMd5Code = this->getMD5(sTimeStr + sPlaintext);

    long sVerifyNum = 0;
    sVerifyNum = sVerifyNum + ((qint32)sMd5Code.mid(0,8).toLongLong(nullptr,16) % 100000000);
    sVerifyNum = sVerifyNum + ((qint32)sMd5Code.mid(8,8).toLongLong(nullptr,16) % 100000000);
    sVerifyNum = sVerifyNum + ((qint32)sMd5Code.mid(16,8).toLongLong(nullptr,16) % 100000000);
    sVerifyNum = sVerifyNum + ((qint32)sMd5Code.mid(24,8).toLongLong(nullptr,16) % 100000000);

    sVerifyNum = qAbs(sVerifyNum);

    QString sVerifyCode = QString::number(sVerifyNum % 10);
    this->addZero(sVerifyCode,1);

    QString sCheckSum =QString::number(((sTimeCode.mid(0,1).toLong()) ^ (sTimeCode.mid(1,1).toLong()) ^ (sTimeCode.mid(2,1).toLong()) ^ sVerifyCode.toLong()) % 10);
    this->addZero(sCheckSum,1);

    int rem = sCheckSum.toInt();

    QString sRetCode;
    switch (rem) {
    case 0:
        sRetCode = sTimeCode.mid(1,1) + sTimeCode.mid(0,1) + sTimeCode.mid(2,1) + sVerifyCode;
        break;
    case 1:
        sRetCode = sVerifyCode + sTimeCode.mid(1,1) + sTimeCode.mid(0,1) + sTimeCode.mid(2,1);
        break;
    case 2:
        sRetCode = sTimeCode.mid(1,1) + sVerifyCode + sTimeCode.mid(0,1) + sTimeCode.mid(2,1);
        break;
    case 3:
        sRetCode = sTimeCode.mid(0,1) + sTimeCode.mid(2,1) + sVerifyCode + sTimeCode.mid(1,1) ;
        break;
    case 4:
        sRetCode = sVerifyCode + sTimeCode.mid(1,1) + sTimeCode.mid(2,1) + sTimeCode.mid(0,1);
        break;
    case 5:
        sRetCode = sTimeCode.mid(0,1) + sVerifyCode + sTimeCode.mid(1,1) + sTimeCode.mid(2,1);
        break;
    case 6:
        sRetCode = sTimeCode.mid(1,1) + sTimeCode.mid(2,1) + sVerifyCode + sTimeCode.mid(0,1);
        break;
    case 7:
        sRetCode = sTimeCode.mid(2,1) + sTimeCode.mid(1,1) + sTimeCode.mid(0,1) + sVerifyCode;
        break;
    case 8:
        sRetCode = sVerifyCode + sTimeCode.mid(0,1) + sTimeCode.mid(2,1) + sTimeCode.mid(1,1);
        break;
    case 9:
        sRetCode = sTimeCode.mid(2,1) + sTimeCode.mid(0,1) + sVerifyCode + sTimeCode.mid(1,1);
        break;
    default:
        throw  QString("内部错误。（sCheckSum = " + sCheckSum + "）");
        break;
    }
    return sCheckSum + sRetCode;
}

QString LibCryptoInQt::VerifyDynamicDigestCode4Len5(QDateTime dValidTime, QString sPlaintext, QString sDynamicDigestCode) throw (QString)
{
    if(sDynamicDigestCode.length()!=5) return "校验长度应是5位。";

    QDateTime initDate(QDate(2000,1,1),QTime(0,0));
    if(dValidTime < initDate) throw QString("时间无效。（" + dValidTime.toString("yyyyMMddhhmm") + "）");

    int rem = qAbs(sDynamicDigestCode.mid(1,1).toLong() ^ sDynamicDigestCode.mid(2,1).toLong() ^ sDynamicDigestCode.mid(3,1).toLong() ^ sDynamicDigestCode.mid(4,1).toLong()) % 10;

    if(sDynamicDigestCode.mid(0,1) != QString::number(rem)) return "校验和不一致。";

    QString sCheckSum = sDynamicDigestCode.mid(0,1);

    long ITimeCode;
    long IVerifyCode;
    switch (sCheckSum.toInt()) {
    case 0:
        //                'sRetCode = Mid(sTimeCode, 2, 1) & Mid(sTimeCode, 1, 1) & Mid(sTimeCode, 3, 1) & sVerifyCode
        ITimeCode = (sDynamicDigestCode.mid(2,1) + sDynamicDigestCode.mid(1,1) + sDynamicDigestCode.mid(3,1)).toLong();
        IVerifyCode = sDynamicDigestCode.mid(4,1).toLong();
        break;
    case 1:
        //    '            sRetCode = sVerifyCode & Mid(sTimeCode, 2, 1) & Mid(sTimeCode, 1, 1) & Mid(sTimeCode, 3, 1)
        ITimeCode = (sDynamicDigestCode.mid(3,1) + sDynamicDigestCode.mid(2,1) + sDynamicDigestCode.mid(4,1)).toLong();
        IVerifyCode = sDynamicDigestCode.mid(1,1).toLong();
        break;
    case 2:
        //    '            sRetCode = Mid(sTimeCode, 3, 1) & sVerifyCode & Mid(sTimeCode, 1, 1) & Mid(sTimeCode, 2, 1)
        ITimeCode = (sDynamicDigestCode.mid(3,1) + sDynamicDigestCode.mid(4,1) + sDynamicDigestCode.mid(1,1)).toLong();
        IVerifyCode = sDynamicDigestCode.mid(2,1).toLong();
        break;
    case 3:
        //    '            sRetCode = Mid(sTimeCode, 1, 1) & Mid(sTimeCode, 3, 1) & sVerifyCode & Mid(sTimeCode, 2, 1)
        ITimeCode = (sDynamicDigestCode.mid(1,1) + sDynamicDigestCode.mid(4,1) + sDynamicDigestCode.mid(2,1)).toLong();
        IVerifyCode = sDynamicDigestCode.mid(3,1).toLong();
        break;
    case 4:
        //    '            sRetCode = sVerifyCode & Mid(sTimeCode, 2, 1) & Mid(sTimeCode, 3, 1) & Mid(sTimeCode, 1, 1)
        ITimeCode = (sDynamicDigestCode.mid(4,1) + sDynamicDigestCode.mid(2,1) + sDynamicDigestCode.mid(3,1)).toLong();
        IVerifyCode = sDynamicDigestCode.mid(1,1).toLong();
        break;
    case 5:
        //    '            sRetCode = sVerifyCode & Mid(sTimeCode, 2, 1) & Mid(sTimeCode, 3, 1) & Mid(sTimeCode, 1, 1)
        ITimeCode = (sDynamicDigestCode.mid(1,1) + sDynamicDigestCode.mid(3,1) + sDynamicDigestCode.mid(4,1)).toLong();
        IVerifyCode = sDynamicDigestCode.mid(2,1).toLong();
        break;
    case 6:
        //    '            sRetCode = Mid(sTimeCode, 2, 1) & Mid(sTimeCode, 3, 1) & sVerifyCode & Mid(sTimeCode, 1, 1)
        ITimeCode = (sDynamicDigestCode.mid(4,1) + sDynamicDigestCode.mid(1,1) + sDynamicDigestCode.mid(2,1)).toLong();
        IVerifyCode = sDynamicDigestCode.mid(3,1).toLong();
        break;
    case 7:
        //    '            sRetCode = Mid(sTimeCode, 3, 1) & Mid(sTimeCode, 2, 1) & Mid(sTimeCode, 1, 1) & sVerifyCode
        ITimeCode = (sDynamicDigestCode.mid(3,1) + sDynamicDigestCode.mid(2,1) + sDynamicDigestCode.mid(1,1)).toLong();
        IVerifyCode = sDynamicDigestCode.mid(4,1).toLong();
        break;
    case 8:
        //    '            sRetCode = sVerifyCode & Mid(sTimeCode, 1, 1) & Mid(sTimeCode, 3, 1) & Mid(sTimeCode, 2, 1)
        ITimeCode = (sDynamicDigestCode.mid(2,1) + sDynamicDigestCode.mid(4,1) + sDynamicDigestCode.mid(3,1)).toLong();
        IVerifyCode = sDynamicDigestCode.mid(2,1).toLong();
        break;
    case 9:
        //    '            sRetCode = Mid(sTimeCode, 3, 1) & Mid(sTimeCode, 1, 1) & sVerifyCode & Mid(sTimeCode, 2, 1)
        ITimeCode = (sDynamicDigestCode.mid(2,1) + sDynamicDigestCode.mid(4,1) + sDynamicDigestCode.mid(1,1)).toLong();
        IVerifyCode = sDynamicDigestCode.mid(3,1).toLong();
        break;
    default:
        throw QString("内部错误。（sCheckSum = " + sCheckSum + "）");
        break;
    }

    long ICTimeCode = (initDate.secsTo(dValidTime) / 60) % 1000;

    QString sTimeStr;
    if(ICTimeCode >= 20){
        if(ICTimeCode <= ITimeCode && ICTimeCode >= ITimeCode - 20){
            sTimeStr =dValidTime.addSecs((ITimeCode - ICTimeCode) * 60).toString("yyyyMMddhhmm");
        }
        else{
            return "超出授权时间范围。";
        }
    }
    else{
        if(ICTimeCode <= ITimeCode || ICTimeCode >= (ITimeCode + 1000 - 20)){
            sTimeStr = dValidTime.addSecs(((ITimeCode + 1000 - ICTimeCode) % 1000) * 60).toString("yyyyMMddhhmm");
        }
        else{
            return "超出授权时间范围。";
        }
    }

    qDebug()<<sTimeStr;
    qDebug()<<sPlaintext;

    QString sMd5Code = this->getMD5(sTimeStr + sPlaintext);
    sMd5Code = sMd5Code.toUpper();

    long sVerifyNum = 0;
    sVerifyNum = sVerifyNum + (qint32)sMd5Code.mid(0,8).toLongLong(nullptr,16) % 100000000;
    sVerifyNum = sVerifyNum + (qint32)sMd5Code.mid(8,8).toLongLong(nullptr,16) % 100000000;
    sVerifyNum = sVerifyNum + (qint32)sMd5Code.mid(16,8).toLongLong(nullptr,16) % 100000000;
    sVerifyNum = sVerifyNum + (qint32)sMd5Code.mid(24,8).toLongLong(nullptr,16) % 100000000;
    sVerifyNum = qAbs(sVerifyNum) % 10;

    if(IVerifyCode != sVerifyNum){
        return "校验错误。";
    }
    return "";
}

QString LibCryptoInQt::getMD5(QString str)
{
    QCryptographicHash md(QCryptographicHash::Md5);
    md.addData(str.toUtf8());
    return md.result().toHex();
}

void LibCryptoInQt::addZero(QString &str, int length)
{
    QString strZero = "";
    for(int i=0;i<length - str.length();i++){
        strZero = strZero + "0";
    }
    str = strZero + str;
}
