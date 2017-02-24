#ifndef METADATAFACTORY
#define METADATAFACTORY

#include <QSharedPointer>

class MetaData;

class MetaDataFactory {
public:
    MetaDataFactory();
    QSharedPointer<MetaData> randomSong(int playlist) const;
};

#endif // METADATAFACTORY

