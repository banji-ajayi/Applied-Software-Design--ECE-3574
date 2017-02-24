#ifndef OBJECTBROWSERMODEL
#define OBJECTBROWSERMODEL

#include <QAbstractItemModel>

class ObjectBrowserModel : public QAbstractItemModel {
public:
    explicit ObjectBrowserModel (QObject* rootObject);

    int columnCount (const QModelIndex &parent = QModelIndex()) const;
    int rowCount (const QModelIndex &parent = QModelIndex()) const;

    QVariant data (const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData (int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QModelIndex index (int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent (const QModelIndex &child) const;

protected:
    QList<QObject*> children(QObject* parent) const;
    QString label(const QObject* widget, int column) const;
    QObject* qObject (const QModelIndex&) const;

private:
    QObject * rootItem;
};

#endif // OBJECTBROWSERMODEL

