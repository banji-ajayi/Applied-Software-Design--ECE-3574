///////////////////////////////
//Thomas Elliott
//905570602
//thomas7@vt.edu
//ECE 3574
//Homework 2 Problem 2
///////////////////////////////

#include "film.h"

Film::Film(QString id, QString title, QString dir, QString length, QDate relDate) {

    m_FilmID = id;
    m_Title = title;
    m_Director = dir;
    m_FilmLength = length;
    m_ReleaseDate = relDate;
}

Film::Film(QStringList& propList) {
    m_FilmID = propList.takeFirst();
    m_Title = propList.takeFirst();
    m_Director = propList.takeFirst();
    m_FilmLength = propList.takeFirst();
    QString tempDate = propList.takeFirst();
    QString year;
    for(int i=0; i<4; ++i){
        year+=tempDate[i];
    }
    QString month;
    month = tempDate[5];
    month += tempDate[6];
    QString day;
    day = tempDate[8];
    day += tempDate[9];
    int intYear = year.toInt();
    int intMonth = month.toInt();
    int intDay = day.toInt();
    m_ReleaseDate.setDate(intYear, intMonth, intDay);
}

QString Film::toString(bool labeled, QString sepChar) {
    if (labeled) {
        return
        QString("%1%2%3%4%5%6%7%8%9%10%11%12").arg("Film").arg(sepChar).arg(m_FilmID).arg(sepChar).arg(m_Title)
                                              .arg(sepChar).arg(m_Director).arg(sepChar)
                                              .arg(m_FilmLength).arg(sepChar).arg(m_ReleaseDate.toString("yyyy-MM-dd"))
                                              .arg(sepChar);
    }
    else {
        return
        QString("%1%2%3%4%5%6%7%8%9%10").arg(m_FilmID).arg(sepChar).arg(m_Title)
                                        .arg(sepChar).arg(m_Director).arg(sepChar)
                                        .arg(m_FilmLength).arg(sepChar).arg(m_ReleaseDate.toString("yyyy-MM-dd"))
                                        .arg(sepChar);
    }

}

QString Film::getFilmID() {
    return m_FilmID;
}

QString Film::getTitle() {
    return m_Title;
}

Educational::Educational(QString id, QString title, QString dir, QString length, QDate relDate, QString subject, int grade) :
    Film::Film(id,title,dir,length, relDate),
    m_Subject(subject),
    m_GradeLevel(grade)
{}

Educational::Educational(QStringList& propList) :
    Film::Film(propList) {
    m_Subject = propList.takeFirst();
    m_GradeLevel = propList.takeFirst().toInt();
}

QString Educational::toString(bool labeled, QString sepChar) {
    if (labeled) {
        return
        QString("%1%2%3%4%5%6%7%8").arg("Education").arg(sepChar).arg(Film::toString(labeled, sepChar))
                                   .arg(sepChar).arg(m_Subject).arg(sepChar).arg(m_GradeLevel)
                                   .arg(sepChar);
    }

    else {
        return
        QString("%1%2%3%4%5%6").arg(Film::toString(labeled, sepChar)).arg(sepChar).arg(m_Subject)
                               .arg(sepChar).arg(m_GradeLevel).arg(sepChar);
    }
}

Entertainment::Entertainment(QString id, QString title, QString dir, QString length,
                             QDate relDate, QString type, QString rating) :
    Film::Film(id,title,dir,length,relDate),
    m_Type(static_cast<FilmTypes>(type.toInt())),
    m_Rating(static_cast<MPAARatings>(rating.toInt()))
{}

Entertainment::Entertainment(QStringList& propList) :
    Film::Film(propList),
    m_Type(static_cast<FilmTypes>(propList.takeFirst().toInt())),
    m_Rating(static_cast<MPAARatings>(propList.takeFirst().toInt()))
{}

QString Entertainment::toString(bool labeled, QString sepChar) {
    if (labeled){
        return
        QString("%1%2%3%4%5%6%7%8").arg("Entertainment").arg(sepChar).arg(Film::toString(labeled, sepChar))
                                   .arg(sepChar).arg(getFilmType()).arg(sepChar).arg(getRating()).arg(sepChar);
    }
    else {
        return
        QString("%1%2%3%4%5%6").arg(Film::toString(labeled, sepChar))
                               .arg(sepChar).arg(getFilmType()).arg(sepChar)
                               .arg(getRating()).arg(sepChar);
    }

}

QString Entertainment::getFilmType() {
    switch (m_Type) {
    case Action: return "Action";
    case Comedy: return "Comedy";
    case SciFi: return "SciFi";
    case Romance: return "Romance";
    case Suspense: return "Suspense";
    case Horror: return "Horror";
    }
    return "0";
}

QString Entertainment::getRating(){
    switch (m_Rating) {
    case G: return "G";
    case PG: return "PG";
    case PG13: return "PG-13";
    case R: return "R";
    case NC17: return "NC-17";
    }
    return "0";
}

FilmList::~FilmList() {
    qDeleteAll(*this);
}

QString FilmList::toString() {
    QStringList films;
    QString sepChar;
       for(int i = 0; i < size(); ++i)
           films << at(i)->toString(true, sepChar);
       return films.join(sepChar);
}

Film* FilmList::findFilm(QString id) {
    for(int i = 0; i < size(); ++i) {
          if(at(i)->getFilmID() == id)
             return at(i);
       }
    return 0;
}

QString FilmList::getID(QString title) {
    for(int i = 0; i < size(); ++i) {
          if(at(i)->getTitle() == title)
             return at(i)->getFilmID();
       }
    return 0;
}

bool FilmList::addFilm(Film*& newFilm) {
    QString id = newFilm->getFilmID();
       Film* existingFilm = findFilm(id);
       if(existingFilm==0) { //film doesn't already exist, so append it
          append(newFilm);
          return true;
       }
       else {
          qDebug() << "The ID: " << newFilm->getFilmID() << " is already in the list so nothing was added." << endl;
          delete newFilm;
          newFilm = 0;
          return false;
       }
}

bool FilmList::removeFilm(QString id) {
      Film* unwantedFilm(findFilm(id));
      if(unwantedFilm == 0) {
          delete unwantedFilm;
          unwantedFilm = 0;
          return false;
      }
      else {
          removeAll(unwantedFilm);
          delete unwantedFilm;
          unwantedFilm = 0;
          return true;
      }
}
