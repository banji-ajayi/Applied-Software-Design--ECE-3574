#include "objectbrowsermodel.h"

#include <QApplication>
#include <QWidget>
#include <QDebug>

ObjectBrowserModel::ObjectBrowserModel(QObject *rootObject) {
    rootItem = rootObject;
}

int ObjectBrowserModel::columnCount(const QModelIndex &parent) const {
    return 3;
}

int ObjectBrowserModel::rowCount(const QModelIndex &parent) const {
    return children(qObject(parent)).count();
}

QVariant ObjectBrowserModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();
    QObject* obj = qObject(index);
    return label( obj, index.column() );
}

QList<QObject*> ObjectBrowserModel::children(QObject *parent) const {
    QList<QObject*> result;
    if (parent == 0) {
        QObjectList ret = rootItem->children();
        foreach(QObject* obj, ret)
            result.append(obj);
    }
    else {
        QObjectList ret = parent->children();
        foreach(QObject* obj, ret)
            result.append(obj);
    }
    qSort (result);
    return result;
}

QVariant ObjectBrowserModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return QAbstractItemModel::headerData(section, orientation, role);

    switch (section) {
    case 0:
        return "Class Name";
    case 1:
        return "Object Name";
    case 2:
        return "Address";
    }

    return QVariant();
}

QString ObjectBrowserModel::label(const QObject* obj, const int column) const {
    switch (column) {
    case 0:
        return obj->metaObject()->className();
    case 1:
        return obj->objectName();
    case 2: {
        QString str;
        str.sprintf("%p", obj);
        return str;
    }
    default:
        return QString();
    }
}

QModelIndex ObjectBrowserModel::index(int row, int col, const QModelIndex &parent) const {
    qDebug() << "row " << row << " row count " << rowCount()
             << " col " << col << " col count " << columnCount();
    if ((row <0) || (col <0) || (row >= rowCount()) || (col >= columnCount()))
        return  QModelIndex();
    return createIndex(row, col, qObject(parent));
}

QModelIndex ObjectBrowserModel::parent(const QModelIndex &index) const {
    if (!index.isValid())
        return QModelIndex();

    QObject* obj = qObject(index)->parent();
    if (obj == 0)
        return QModelIndex();

    QObject* parent = obj->parent();
    QList<QObject*> result  = children(parent);
    int row = result.indexOf(obj);
    return createIndex(row, 0, parent);
}

QObject* ObjectBrowserModel::qObject(const QModelIndex &index) const {
    if (index.isValid()) {
        QObject* parent = reinterpret_cast<QObject*>(index.internalPointer());
        return children(parent)[index.row()];
    }
    return 0;
}
