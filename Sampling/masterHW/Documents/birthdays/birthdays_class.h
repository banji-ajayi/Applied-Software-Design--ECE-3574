//////////////////////////////////
//Thomas Elliott
//905570602
//thomas7@vt.edu
//ECE 3574
//Homework 1
//////////////////////////////////

#ifndef BIRTHDAYS_CLASS_H
#define BIRTHDAYS_CLASS_H

#include <QTextStream>
#include <QCoreApplication>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QList>
#include <QDate>
#include <Qt>
#include <QDebug>

struct bdayNode {
    QString name;
    QDate date;
};

class birthdays {

    public:
        //all member functions to go here

        void displayList(QList<bdayNode>);
        void displayTimeLeft(QList<bdayNode>);
        void listNext30Days(QList<bdayNode>);
        void sortBirthdays(QList<bdayNode>& list);
        void sortBirthdaysAlphabetically(QList<bdayNode>& list);
        void setBirthday(QList<bdayNode>& list, QString, QString);
        void listNextXDays(QList<bdayNode>, int);
        void findBirthdaysWith(QList<bdayNode>, QString);
        void deleteByDate(QList<bdayNode>& list, QDate);
        void deleteByName(QList<bdayNode>& list, QString);
        void listNextXDaysAfterPerson(QList<bdayNode>, QString, int);
        QList<bdayNode> updateBirthdays(QList<bdayNode>& list);


    private:

};
#endif // BIRTHDAYS_CLASS_H
