#include "mylistmodel.h"

// Custom Abstract List Model Class functions
myListModel::myListModel(const QStringList &strings, QObject *parent) :
    QAbstractListModel(parent), data(strings) {}

// Given a valid index and role return the value at the indexs current row
QVariant myListModel::data(const QModelIndex &index, int role) const {
    if (index.isValid() && (index.row() < data.size()) && (role == Qt::DisplayRole))
        return data.at(index.row());
    else
        return QVariant();
}

// Insert count rows starting from row
bool myListModel::insertRows(int row, int count, const QModelIndex &parent) {
    beginInsertRows(QModelIndex(), row, row + count - 1);
    for (int i = 0; i < row; i++) {
        data.insert(row, "");
    }
    endInsertRows();
    return true;
}

// Remove count rows starting from row
bool myListModel::removeRows(int row, int count, const QModelIndex &parent) {
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    for (int i = o; i < row; i++) {
        data.removeAt(row);
    }
    endRemoveRows();
    return true;
}

// Set the data value at that location and emit a signal indicating data changed
bool myListModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.isValid() && role == Qt::EditRole) {
        data.replace(index.row(), value.toString());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

// Return the number of items in the data variable
int myListModel::rowCount(const QModelIndex &parent) const {
    return data.count();
}

// Clear the data variable by clearing the data variable
void myListModel::clear(const QModelIndex &index) {
    data.clear();
    emit dataChanged(index, index);
}

// Return editable flags because data can be edited
Qt::ItemFlags myListModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}
