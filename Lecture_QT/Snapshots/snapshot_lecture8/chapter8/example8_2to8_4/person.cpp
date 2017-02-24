#include <QObject>
#include <QString>
#include "person.h"

#include <QTextStream>

static QTextStream qtCout(stdout);

Person::Person(QString name, QObject* parent)
    : QObject(parent) {
    setObjectName(name);
    qtCout << QString("Constructing Person %1").arg(name) << endl;
}

Person::~Person() {
    qtCout << QString("Destroying Person: %1").arg(objectName()) << endl;
}
