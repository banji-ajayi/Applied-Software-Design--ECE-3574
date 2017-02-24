#ifndef SOURCELISTMODEL
#define SOURCELISTMODEL

#include <QAbstractListModel>
#include <QList>

#include "metadatatablemodel.h"

class SourceListModel : public QAbstractListModel {
    Q_OBJECT
public:
    SourceListModel(QObject* parent=0);
    virtual ~SourceListModel();
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    MetaDataTableModel* playList(int row) const;

    bool hasChildren(const QModelIndex &parent) const {return false;}

    Qt::DropActions supportedDropActions() const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);

private:
    QList<MetaDataTableModel*> m_playlists;

    void populateSamples();
    MetaDataTableModel* randomModel(int i);
};

#endif // SOURCELISTMODEL

