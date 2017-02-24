#ifndef METADATAVALUE_H
#define METADATAVALUE_H

class MetaDataValue {
public:
    friend QTextStream& operator<< (QTextStream& os, const MetaDataValue& mdv);
    friend QTextStream& operator>> (QTextStream& is, MetaDataValue& mdv);

    friend QDataStream& operator<< (QDataStream& os, const MetaDataValue& mdv);
    friend QDataStream& operator>> (QDataStream& is, MetaDataValue& mdv);

    friend bool operator== (const MetaDataValue& mdv1, const MetaDataValue& mdv2);

    MetaDataValue() : m_isNull(true) {}
    MetaDataValue(const MetaDataValue& other);
    MetaDataValue& operator=(const MetaDataValue& other);
    virtual ~MetaDataValue() {}

    virtual QString fileName() const;
    virtual QString genre() const;
    virtual QString artist() const;
    virtual QString albumTitle() const;
    virtual QString trackTitle() const;
    virtual QString trackNumber() const;
    virtual const QImage &image() const;
    virtual QTime trackTime() const;
    virtual QString trackTimeString() const;
    virtual QString comment() const;
    virtual bool isNull() const;
    virtual QUrl url() const;

    virtual void setFileName(QString fileName);
    virtual void setGenre(const QString& newGenre);
    virtual void setArtist(const QString& newArtist);
    virtual void setAlbumTitle(const QString& newAlbumTitle);
    virtual void setTrackTitle(const QString& nnewTitle);
    virtual void setTrackNumber(const QString& newTracjNumber);
    virtual void setImage(const QImage& img);
    virtual void setTrackTime(const QTime& time);
    virtual void setComment(const QString& newComment);
    virtual void setNull(bool n);
    virtual void setUrl(QUrl url);

protected:
    bool m_isNull;
    QUrl m_Url;
    QString m_TrackNumber;
    QString m_TrackTitle;
    QString m_Comment;
    QString m_Genre;
    QString m_Artist;
    QTime m_TrackTime;
    QString m_AlbumTitle;
    QImage m_Image;
};

Q_DECLARE_METATYPE(MetaDataValue); //adds to QVariant type system

#endif // METADATAVALUE_H

