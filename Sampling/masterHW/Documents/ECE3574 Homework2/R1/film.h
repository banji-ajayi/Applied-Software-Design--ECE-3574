#ifndef FILM_H
#define FILM_H

///////////////////////////////
//Thomas Elliott
//905570602
//thomas7@vt.edu
//ECE 3574
//Homework 2 Problem 2
///////////////////////////////

#include <QString>
#include <QStringList>
#include <QDate>
#include <QDebug>
#include <QTextStream>

class Film {

    public:
        Film(QString, QString, QString, QString, QDate);
        Film(QStringList&);
        virtual QString toString(bool, QString sepChar="[::]");
        QString getFilmID();
        QString getTitle();

    private:
        QString m_FilmID;
        QString m_Title;
        QString m_Director;
        QString m_FilmLength;
        QDate m_ReleaseDate;
};

class Educational : public Film {

    public:
        Educational(QString, QString, QString, QString, QDate, QString, int);
        Educational(QStringList&);
        virtual QString toString(bool, QString sepChar="[::]");

    private:
        QString m_Subject;
        int m_GradeLevel;
};

class Entertainment : public Film {

    enum FilmTypes {Action =1, Comedy, SciFi, Romance, Suspense, Horror};
    enum MPAARatings {G=1, PG, PG13, R, NC17};

    public:
        Entertainment(QString, QString, QString, QString, QDate, QString, QString);
        Entertainment(QStringList&);
        virtual QString toString(bool, QString sepChar="[::]");
        QString getFilmType();
        QString getRating();

    private:
        FilmTypes m_Type;
        MPAARatings m_Rating;
};

class FilmList : public QList<Film*> {

    public:
        ~FilmList();
        QString toString();
        Film* findFilm(QString);
        QString getID(QString);
        bool addFilm(Film*& newFilm);
        bool removeFilm(QString);
};

#endif // FILM_H
