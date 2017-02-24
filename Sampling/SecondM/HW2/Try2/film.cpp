#include "film.h"
#include <typeinfo>

Film::Film(QString id, QString title, QString dir, quint32 len, QDate relDate)
    : m_FilmID(id), m_Title(title), m_Director(dir), m_FilmLength(len), m_ReleaseDate(relDate) {}

Film::Film(QStringList propList) {
    m_FilmID = propList.at(0);
    m_Title = propList.at(1);
    m_Director = propList.at(2);
    m_FilmLength = propList.at(3).toInt();
    m_ReleaseDate = QDate::fromString(propList.at(4), "yyyy-MM-dd");
}

QString Film::getID() {
    return m_FilmID;
}

QString Film::getTitle() {
    return m_Title;
}

bool Film::operator==(Film &rhs) {
    if(typeid(this).name() == typeid(rhs).name()) {
        return this->m_Title == rhs.m_Title;
    }
    else
        return false;
}

QString Film::toString(bool labeled, QString sepchar) {
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
