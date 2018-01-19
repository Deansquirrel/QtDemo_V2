#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QList>
#include <QVariant>
#include <QJsonObject>

class Menu : public QObject
{
    Q_OBJECT
public:
    explicit Menu(QObject *parent = nullptr);

    Q_INVOKABLE QList<QVariant> getMenuModel();

signals:

public slots:

private:
    void clearJson(QJsonObject &json);
};

#endif // MENU_H
