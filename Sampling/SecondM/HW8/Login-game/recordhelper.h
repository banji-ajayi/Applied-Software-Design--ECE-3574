#ifndef RECORDHELPER_H
#define RECORDHELPER_H

#include <QDataStream>

struct Record {
    QString username;
    QString color;
    QByteArray digest;
};

QDataStream& operator>>(QDataStream& s, Record& r);
QDataStream& operator<<(QDataStream& s, const Record& r);

#endif // RECORDHELPER_H
