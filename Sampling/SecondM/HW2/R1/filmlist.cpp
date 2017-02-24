#include "filmlist.h"
#include <QDebug>


QString FilmList::toString() {
     qDebug() << "  DEBUG:  FilmList toString" << endl;
    QString retString;
    for(int i = 0; i < m_list.size(); i++) {
        retString += m_list.at(i)->toString(true, ",") + "\n";
    }
    return retString;
}

Film* FilmList::findFilm(QString id) {
    qDebug() << "   DEBUG: FilmList findFilm" << endl;
    Film* retFilm;
    for(int i = 0; i < m_list.size(); i++) {
        if(m_list.at(i)->getID() == id)
            retFilm = m_list.at(i);
    }
    return retFilm;
}

QStringList FilmList::getID(QString title) {
    qDebug() << "   DEBUG: FilmList getID" << endl;
    QStringList results;
    for(int i = 0; i < m_list.size(); i++) {
        if (m_list.at(i)->getTitle() == title)
            results.append(m_list.at(i)->getID());
    }
    return results;
}


void FilmList::addFilm(Film* fim) {
    qDebug() << "   DEBUG: FilmList addFilm" << endl;
    if(!m_list.contains(fim))
        m_list.append(fim);
    qDebug() << fim << "is now added" << endl;
}

void FilmList::removeFilm(QString filmID) {
    qDebug() << "   DEBUG: FilmList removeFilm" << endl;
    for(int i = 0; i < m_list.size(); i++) {
        if(m_list.at(i)->getID() == filmID) {
            m_list.removeAt(i);
            i--;
        }
    }
}
