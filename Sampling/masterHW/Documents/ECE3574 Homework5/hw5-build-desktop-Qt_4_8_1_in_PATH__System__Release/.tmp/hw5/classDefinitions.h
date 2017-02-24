#ifndef CLASSDEFINITIONS_H
#define CLASSDEFINITIONS_H

#include <QDataStream>

struct record {
    QString name;
    QString color;
    QByteArray digest;
};

QDataStream& operator>>(QDataStream& s, record& r);
QDataStream& operator<<(QDataStream& s, const record& r);

#endif // CLASSDEFINITIONS_H
