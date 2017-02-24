#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H

#include "film.h"

enum FilmTypes {Action = 1, Comedy = 2, SciFi = 3, Horror = 4};
enum MPAARatings {G = 1, PG = 2, PG13 = 3, R = 4, NC17 = 5};

class Entertainment : public Film {
    public:
        Entertainment(QString id, QString title, QString dir, quint32 len, QDate relDate, FilmTypes type, MPAARatings rtng);
        Entertainment(QStringList propList);
        QString toString(bool labeled, QString sepchar);
    private:
        FilmTypes m_Type;
        MPAARatings m_Rating;
};


#endif // ENTERTAINMENT_H
