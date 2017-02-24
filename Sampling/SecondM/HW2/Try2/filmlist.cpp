#include "filmlist.h"

QString FilmList::toString() {
    QString retString;
    for(int i = 0; i < m_list.size(); i++) {
        retString += m_list.at(i)->toString(true, ",") + "\n";
    }
    return retString;
}

QStringList FilmList::getID(QString title) {
    QStringList results;
    for(int i = 0; i < m_list.size(); i++) {
        if (m_list.at(i)->getTitle() == title)
            results.append(m_list.at(i)->getID());
    }
    return results;
}

Film* FilmList::findFilm(QString id) {
    Film* retFilm;
    for(int i = 0; i < m_list.size(); i++) {
        if(m_list.at(i)->getID() == id)
            retFilm = m_list.at(i);
    }
    return retFilm;
}

void FilmList::addFilm(Film* fim) {
    if(!m_list.contains(fim))
        m_list.append(fim);
}

void FilmList::removeFilm(QString filmID) {
    for(int i = 0; i < m_list.size(); i++) {
        if(m_list.at(i)->getID() == filmID) {
            m_list.removeAt(i);
            i--;
        }
    }
}
