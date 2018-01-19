#ifndef QMLCOM_H
#define QMLCOM_H

#include <QObject>

class QMLCom : public QObject
{
    Q_OBJECT
public:
    explicit QMLCom(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QMLCOM_H