/////////////////////////////////////////
// Jacob Melton
// 905698368
// jmelton1@vt.edu
// ECE3574
// Homework 1
/////////////////////////////////////////

#ifndef PERSON_H
#define PERSON_H

#include <QDate>
#include <QString>

// Header file defining the members of the Person class

class Person {
    QString name;
    QDate   birthday;
public:
    Person();
    Person(QString newName);
    Person(QString newName, QDate newBirthday);
    void setName(QString newName);
    void setBirthday(QDate newBirthday);
    QString getName();
    QDate getBirthday();
};

#endif // PERSON_H
