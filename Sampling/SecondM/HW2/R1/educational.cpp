#include "educational.h"
#include <QDebug>

Educational::Educational(QString id, QString title, QString dir, quint32 len,
                         QDate relDate, QString subject, Grade grade)
    : Film(id, title, dir, len, relDate)
{
    m_Subject = subject;
    m_GradeLevel = grade;
}

Educational::Educational(QStringList propList)
    : Film(propList.at(0), propList.at(1), propList.at(2), propList.at(3).toInt(), QDate::fromString(propList.at(4), "yyyy-MM-dd"))
{
    qDebug() << " ----------- propList ran for educational ---------" << endl;
    m_Subject = propList.at(5);
    m_GradeLevel = static_cast<Grade>(propList.at(6).toInt());
}

QString Educational::toString(bool labeled, QString sepchar) {
    QString retString;
    if(labeled) {
        retString = this->toString(true, sepchar)
                + "Subject: " + m_Subject + sepchar
                + "Grade Level: " + m_GradeLevel + sepchar;
    }
    else {
        retString = this->toString(true, sepchar)
                + m_Subject + sepchar
                + m_GradeLevel + sepchar;
    }

    return retString;
}
