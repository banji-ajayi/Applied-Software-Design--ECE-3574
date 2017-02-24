
#include <QVariant>
#include <QString>
#include <QTextStream>
#include <QDataStream>
#include <QUrl>
#include <QTime>
#include <QImage>

#include "metadatavalue.h"

QString MetaDataValue::fileName() const {
    return m_Url.toLocalFile();
}
MetaDataValue::MetaDataValue(const MetaDataValue &other) {
    *this = other;
}

MetaDataValue& MetaDataValue::operator=(const MetaDataValue& other) {
    if (this == &other)
        return *this;
    m_isNull = other.isNull();
    if (m_isNull)
        return *this;
    setImage(other.image());
    setUrl(other.url());
    setTrackTitle(other.trackTitle());
    setArtist(other.artist());
    setAlbumTitle(other.albumTitle());
    setTrackNumber(other.trackNumber());
    setTrackTime(other.trackTime());
    setComment(other.comment());
    setGenre(other.genre());
    return *this;
}

const QImage& MetaDataValue::image() const {
    return m_Image;
}

void MetaDataValue::setFileName(QString fileName) {
    m_Url = QUrl::fromLocalFile(fileName);
    m_isNull = false;
}

QString MetaDataValue::genre() const {
    return m_Genre;
}

QString MetaDataValue::artist() const {
    return m_Artist;
}

QString MetaDataValue::albumTitle() const {
    return m_AlbumTitle;
}

QString MetaDataValue::trackTitle() const {
    if (m_TrackTitle == QString())
    {
        return fileName();
    }
    return m_TrackTitle;
}

QString MetaDataValue::trackNumber() const {
    return m_TrackNumber;
}

QTime MetaDataValue::trackTime() const {
    return m_TrackTime;
}

QString MetaDataValue::trackTimeString() const {
    QTime t = m_TrackTime;
    if (t.hour() > 0) {
            return t.toString("hh:mm:ss");
    }
    else {
        return t.toString("m:ss");
    }
}

QString MetaDataValue::comment() const {
     return m_Comment;
}

void MetaDataValue::setGenre(const QString& newGenre) {
    m_Genre = newGenre;
}

void MetaDataValue::setArtist(const QString &newArtist) {
    m_Artist = newArtist;
}

void MetaDataValue::setTrackNumber(const QString& newTrackNum) {
    m_TrackNumber = newTrackNum;
}

void MetaDataValue::setTrackTitle(const QString &nnewTitle) {
    m_isNull = false;
    m_TrackTitle = nnewTitle;
}

void MetaDataValue::setAlbumTitle(const QString &newAlbumTitle) {
    m_AlbumTitle = newAlbumTitle;
}

void MetaDataValue::setComment(const QString &newComment) {
    m_Comment = newComment;
    if (m_Comment.contains("\n"))
        m_Comment.replace("\n", " ");
}

bool MetaDataValue::isNull() const {
    return m_isNull;
}

void MetaDataValue::setNull(bool n) {
    m_isNull = n;
}

QUrl MetaDataValue::url() const {
    return m_Url;
}

void MetaDataValue::setUrl(QUrl url) {
    m_Url = url;
}

/* friends */

bool operator==(const MetaDataValue& mdv1, const MetaDataValue& mdv2) {
    if (mdv1.url() != mdv2.url())
        return false;
    if (mdv1.trackTitle() != mdv2.trackTitle())
        return false;
    if (mdv1.trackTimeString() != mdv2.trackTimeString())
        return false;
    if (mdv1.albumTitle() != mdv2.albumTitle())
        return false;
    if (mdv1.comment() != mdv2.comment())
        return false;
    if (mdv1.trackNumber() != mdv2.trackNumber())
        return false;
    if (mdv1.artist() != mdv2.artist())
        return false;
    if (mdv1.genre() != mdv2.genre())
        return false;
    if (mdv1.isNull())
        return false;
    return true;
}

QTextStream& operator<< (QTextStream& os, const MetaDataValue& mdv) {
    QStringList s1;
    s1 << mdv.url().toString() << mdv.trackTitle() << mdv.artist() << mdv.albumTitle()
       << mdv.trackNumber() << mdv.trackTime().toString("m:ss")
       << mdv.genre() << mdv.comment();
    os << s1.join("\t") << "\n";
    return os;
}

QTextStream& operator>> (QTextStream& is, MetaDataValue& mdv) {
    QString line = is.readLine();
    QStringList fields = line.split("\t");
    while (fields.size() < 8)
        fields << "";

    mdv.m_isNull = false;
    mdv.setUrl(QUrl::fromUserInput(fields[0]));
    mdv.setTrackTitle(fields[1]);
    mdv.setArtist(fields[2]);
    mdv.setAlbumTitle(fields[3]);
    mdv.setTrackNumber(fields[4]);
    QTime t = QTime::fromString(fields[5], "m:ss");
    mdv.setTrackTime(t);
    mdv.setGenre(fields[6]);
    mdv.setComment(fields[7]);
    return is;
}

QDataStream& operator<< (QDataStream& os, const MetaDataValue& mdv) {
    os << mdv.m_Url <<  mdv.trackTitle() << mdv.artist() << mdv.albumTitle()
       << mdv.trackNumber() << mdv.trackTime() << mdv.genre()
       << mdv.comment() << mdv.image();
    return os;
}

QDataStream& operator>> (QDataStream& is, MetaDataValue& mdv) {
    is >> mdv.m_Url >>  mdv.m_TrackTitle >> mdv.m_Artist >> mdv.m_AlbumTitle
       >> mdv.m_TrackNumber >> mdv.m_TrackTime >> mdv.m_Genre
       >> mdv.m_Comment >> mdv.m_Image;
    mdv.m_isNull = false;
    return is;
}
