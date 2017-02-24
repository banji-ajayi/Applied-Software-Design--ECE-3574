#ifndef METADATA
#define METADATA

#include <QTime>
#include <QTextStream>
#include <QString>

#include "starrating.h"

class MetaData: public QObject {
    Q_OBJECT
    Q_PROPERTY(QString TrackTitle READ trackTitle WRITE setTrackTitle);
    Q_PROPERTY(QString Artist READ artist WRITE setArtist);
    Q_PROPERTY(QTime TrackTime READ trackTime WRITE setTrackTime);
    Q_PROPERTY(QString AlbumTitle READ albumTitle WRITE setAlbumTitle);
    Q_PROPERTY(int TrackNumber READ trackNumber WRITE setTrackNumber);
    Q_PROPERTY(QString Genre READ genre WRITE setGenre);
    Q_PROPERTY(StarRating Rating READ rating WRITE setRating);
    Q_PROPERTY(QString Comment READ comment WRITE setComment);
    Q_PROPERTY(QString FileName READ fileName WRITE setFileName);

public:
    MetaData(QObject* parent=0)
        : QObject(parent)
    { }
    virtual ~MetaData() {};

public:
    virtual QString trackTitle() const {return m_trackTitle;}
    virtual QString artist() const {return m_artist;}
    virtual QTime trackTime() const {return m_trackTime;}
    virtual QString trackTimeString() const {
        QTime t =m_trackTime;
        if (t.hour() > 0)
            return t.toString("hh:mm:ss");
        else
            return t.toString("m::ss");
    }
    virtual QString albumTitle() const {return m_albumTitle;}
    virtual int trackNumber() const {return m_trackNumber;}
    virtual QString genre() const {return m_genre;}
    virtual StarRating rating() const {return m_rating;}
    virtual QString comment() const {return m_comment;}
    virtual QString fileName() const {return m_fileName;}

public slots:
    virtual void setTrackTitle(const QString& title) {
        m_trackTitle = title;
    }
    virtual void setArtist(const QString& artist) {
        m_artist = artist;
    }
    virtual void setTrackTime(const QTime& time) {
        m_trackTime = time;
    }
    virtual void setAlbumTitle(const QString& title) {
        m_albumTitle = title;
    }
    virtual void setTrackNumber(int n) {
        m_trackNumber = n;
    }
    virtual void setGenre(const QString& genre) {
        m_genre = genre;
    }
    virtual void setRating(StarRating rating) {
        m_rating = rating;
    }
    virtual void setComment(const QString& comment) {
        m_comment = comment;
    }
    virtual void setFileName(const QString& fileName) {
        m_fileName = fileName;
    }

private:
    QString m_trackTitle;
    QString m_artist;
    QTime m_trackTime;
    QString m_albumTitle;
    int m_trackNumber;
    QString m_genre;
    StarRating m_rating;
    QString m_comment;
    QString m_fileName;
};

#endif // METADATA

