#ifndef CRYPTOINQT_H
#define CRYPTOINQT_H

#include <QObject>
#include <QDebug>
#include <QDateTime>

#include "LibCryptoInQt.h"

class CryptoInQt : public QObject
{
    Q_OBJECT
public:
    explicit CryptoInQt(QObject *parent = nullptr);

    Q_INVOKABLE void subTest();

    Q_INVOKABLE QString createCode(QString sPlaintext);

    Q_INVOKABLE QString checkCode(QString sPlaintext ,QString code);

    Q_INVOKABLE QString sPlaintext() const;

signals:

public slots:

private:
    QString _sPlaintext;
};

#endif // CRYPTOINQT_H
