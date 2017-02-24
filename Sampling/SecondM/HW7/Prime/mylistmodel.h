#ifndef MYLISTMODEL_H
#define MYLISTMODEL_H

#include <QAbstractListModel>

class myListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit myListModel(const QStringList &strings, QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    void clear(const QModelIndex &index = QModelIndex());
    int rowCount(const QModelIndex &parent) const;

private:
    QStringList data;
};

#endif // MYLISTMODEL_H
