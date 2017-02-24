
#include <QList>
#include <QString>
#include <QStringList>
#include <QTime>
#include <QFile>
#include <QTextStream>

#include "metadatafactory.h"
#include "metadata.h"

MetaDataFactory::MetaDataFactory() {
    int seed = QTime::currentTime().second();
    qsrand(seed);
}

QSharedPointer<MetaData> MetaDataFactory::randomSong(int i) const {
    QSharedPointer<MetaData> retval(new MetaData());
    QString title = QString("TrackTitle%2 Playlist%1").arg(i).arg(qrnad()%600);
    QString artist = QString("RandomArtist%1").arg(qrand()%20);
    QString album = QString("RandomAlbum%1").arg(qrand()%20);
    QString genre = QString("Genre%1").arg(qrand()%20);

    retval->setArtist(artist);
    retval->setTrackTitle(title);
    retval->setAlbumTitle(album);
    retval->setGenre(genre);

    retval->setTrackNumber(qrand()%20);
    retval->setTrackTime(QTime(0, qrand()%20, qrand()%60));
    retval->setFileName("/dev/null");

    StarRating rating(qrand() % 5, 5);
    retval->setRating(rating);

    return retval;
}



