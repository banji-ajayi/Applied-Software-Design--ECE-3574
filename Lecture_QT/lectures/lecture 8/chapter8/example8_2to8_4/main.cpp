#include <QCoreApplication>
#include <QDebug>

#include <QObject>
#include <QString>
#include "person.h"

void check_qobject (QObject qo) { //NOTE QObject cannot be copied - but the compiler will not complain about a function that is not used!
    qDebug() << qo.objectName() << endl;
}

void check_person (Person p) {
    qDebug() << p.objectName() << endl;
}

void dumpBunch(QObject& b) {
    QList<QObject*> bunchers = b.findChildren<QObject*>(); //NOTE This function do a recursive search (therefore, it traverses the objects tree)
    qDebug() << b.objectName();
    foreach (const QObject* current, bunchers) {
        qDebug() << " " << current->objectName();
    }
}
//NOTE you can use const QObectList& QObject::children() const to get a list of children

void growBunch() {

    QObject bunch;
    bunch.setObjectName("A Stack Object");

    Person* mike = new Person("Mike", &bunch);
    Person* carol = new Person("Carol", &bunch);
    new Person("Greg", mike);
    new Person("Peter", mike);
    new Person("Bobby", mike);
    new Person("Marcia", carol);
    new Person("Jan", carol);
    new Person("Cindy", carol);
    new Person("Alice"); //NOTE she doesn't have a parent so no one is destroying her
    Person another("Antonio", &bunch);

    qDebug() << "Display the list using QObject::dumpObjectTree()" << endl;
    bunch.dumpObjectTree();
//    bunch.dumpObjectInfo(); //NOTE These two are said to do not print on IO if the library is not compiled with debug symbols
    dumpBunch(bunch);

    qDebug() << "What about copying etc?" << endl;
//    check_qobject(bunch); //ERROR QObject::QObject is private
    check_person(another);
    qDebug() << "Ready to return from growBunch() - destroy local objects" << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    growBunch();
    qDebug() << "What happened to Alice?" << endl;

    return EXIT_SUCCESS;
}

