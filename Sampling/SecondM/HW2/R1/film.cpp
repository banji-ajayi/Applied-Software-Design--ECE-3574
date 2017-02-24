#include "film.h"
#include <typeinfo>

Film::Film(QString id, QString title, QString dir, quint32 len, QDate relDate)
    : m_FilmID(id), m_Title(title), m_Director(dir), m_FilmLength(len), m_ReleaseDate(relDate) {
    qDebug() << "   Debug: Film Constructor" << endl;

    qDebug() << "Output of Film Constructor is: " << m_FilmID << m_Title << m_Director << m_FilmLength << m_ReleaseDate << endl;
    }

Film::Film(QStringList propList) {
    qDebug() << " ----------- propList ran for film ---------" << endl;
    m_FilmID = propList.at(0);
    m_Title = propList.at(1);
    m_Director = propList.at(2);
    m_FilmLength = propList.at(3).toInt();
    m_ReleaseDate = QDate::fromString(propList.at(4), "yyyy-MM-dd");
}

QString Film::getID() {
     qDebug() << "  DEBUG: Film getID" << endl;
    return m_FilmID;
}

QString Film::getTitle() {
     qDebug() << "  DEBUG: Film getTitle" << endl;
    return m_Title;
}

bool Film::operator==(Film &rhs) {
    qDebug() << "   DEBUG: Film operator ==" << endl;
    if(typeid(this).name() == typeid(rhs).name()) {
        return this->m_Title == rhs.m_Title;
    }
    else
        return false;
}

QString Film::toString(bool labeled, QString sepchar) {
     qDebug() << "  DEBUG: Film toString" << endl;
    QString retString;
    if(labeled) {
        retString = "ID: " + m_FilmID + sepchar
                + "Title: " + m_Title + sepchar
                + "Director: " + m_Director + sepchar
                + "Length (min): " + QString::number(m_FilmLength) + sepchar
                + "Release Date: " + m_ReleaseDate.toString("yyyy-MM-dd") + sepchar;
    }
    else {
        retString = m_FilmID + sepchar
                + m_Title + sepchar
                + m_Director + sepchar
                + m_FilmLength + sepchar
                + m_ReleaseDate.toString("yyyy-MM-dd") + sepchar;
    }

    return retString;
}
