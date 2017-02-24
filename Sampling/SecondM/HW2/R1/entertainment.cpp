#include "entertainment.h"
#include <QDebug>

Entertainment::Entertainment(QString id, QString title, QString dir, quint32 len,
                             QDate relDate, FilmTypes type, MPAARatings rtng)
    : Film(id, title, dir, len, relDate)
{
    m_Type = type;
    m_Rating = rtng;
}

Entertainment::Entertainment(QStringList propList)
    : Film(propList.at(0), propList.at(1), propList.at(2), propList.at(3).toInt(), QDate::fromString(propList.at(4), "yyyy-MM-dd"))
{
    qDebug() << " ----------- propList ran for entertainment ---------" << endl;
    m_Type = static_cast<FilmTypes>(propList.at(5).toInt());
    m_Rating = static_cast<MPAARatings>(propList.at(6).toInt());
}

QString Entertainment::toString(bool labeled, QString sepchar) {
    QString retString;
    if(labeled) {
        retString = this->toString(true, sepchar)
                + "Film Type: " + m_Type + sepchar
                + "Rating: " + m_Rating + sepchar;
    }
    else {
        retString =this->toString(true, sepchar)
                + m_Type + sepchar
                + m_Rating + sepchar;
    }

    return retString;
}
