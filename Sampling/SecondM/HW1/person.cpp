/////////////////////////////////////////
// Jacob Melton
// 905698368
// jmelton1@vt.edu
// ECE3574
// Homework 1
/////////////////////////////////////////

#include "person.h"

/*
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

*/

// Implementation of the Person class functions

// Default constructor
Person::Person() {
    name = QString();
    birthday = QDate();
}

// Constructor with name only
Person::Person(QString newName) {
    name = newName;
    birthday = QDate();
}

// Constructor with name and birthday
Person::Person(QString newName, QDate newBirthday) {
    name = newName;
    birthday = newBirthday;
}

// Name setter function
void Person::setName(QString newName)
{
    name = newName;
}

// Birthday setter function
void Person::setBirthday(QDate newBirthday)
{
    birthday = newBirthday;
}

// Name getter function
QString Person::getName()
{
    return name;
}

// Birthday getter function
QDate Person::getBirthday()
{
    return birthday;
}
