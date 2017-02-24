#ifndef FILMLIST_H
#define FILMLIST_H

#include <QList>
#include "film.h"

class FilmList : public QList<Film*> {
    public:
        QStringList getID(QString title);
        QString toString();
        Film* findFilm(QString id);
        void addFilm(Film* fim);
        void removeFilm(QString filmID);
    private:
        QList<Film*> m_list;
};

#endif // FILMLIST_H
