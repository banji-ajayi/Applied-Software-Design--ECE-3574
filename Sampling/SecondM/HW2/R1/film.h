#ifndef FILM_H
#define FILM_H

#include <QStringList>
#include <QString>
#include <QDate>
#include <QDebug>

typedef quint32 Length;

class Film {
    public:
        Film(QString id, QString title, QString dir, quint32 len, QDate relDate);
        Film(QStringList propList);
        QString getID();
        QString getTitle();
        bool operator==(Film &rhs);
        virtual QString toString(bool labeled, QString sepchar);
    private:
        QString m_FilmID;
        QString m_Title;
        QString m_Director;
        Length m_FilmLength;
        QDate m_ReleaseDate;
};

#endif // FILM_H
