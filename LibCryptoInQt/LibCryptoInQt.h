#ifndef LIBCRYPTOINQT_H
#define LIBCRYPTOINQT_H

#include "libcryptoinqt_global.h"

#include <QDateTime>
#include <QCryptographicHash>
#include <QDebug>
#include <QException>

class LIBCRYPTOINQTSHARED_EXPORT LibCryptoInQt
{

public:
    LibCryptoInQt();

    /**
     * @brief CalcDynamicDigestCode4Len5 生成5位动态数字摘要字符串（正负十分钟内有效）
     * @param dValidTime 有效时间
     * @param sPlaintext 明文
     * @return 动态摘要字符串
     * @throw QString 异常信息
     */
    QString CalcDynamicDigestCode4Len5(QDateTime dValidTime, QString sPlaintext) throw(QString);

    /**
     * @brief VerifyDynamicDigestCode4Len5 校验5位动态数字摘要字符串是否有效（正负十分钟内有效）
     * @param dValidTime 有效时间
     * @param sPlaintext 明文
     * @param sDynamicDigestCode 动态摘要字符串
     * @return 验证结果，空字符串表示验证通过，不为空则表示验证不通过，返回的字符串为错误信息
     * @throw QString 异常信息
     */
    QString VerifyDynamicDigestCode4Len5(QDateTime dValidTime, QString sPlaintext, QString sDynamicDigestCode) throw (QString);

private:
    /**
     * @brief getMD5 获取字符串的MD5值
     * @param str
     * @return
     */
    QString getMD5(QString str);

    /**
     * @brief addZero
     * @param str
     * @param length 长度
     */
    void addZero(QString &str,int length);

};

#endif // LIBCRYPTOINQT_H
