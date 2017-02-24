#include "mainwindow.h"
#include <QApplication>

#include <QStandardItem>
#include <QStandardItemModel>

#include <QtGui>
#include <QSplitter>
#include <QListView>
#include <QTableView>
#include <QTreeView>
#include <QColumnView>
#include <QHeaderView>

#include "createmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStandardItemModel* model = createModel(&a);
    QSplitter vsplitter(Qt::Vertical);
    QSplitter hsplitter;

    QListView list;
    QTableView table;
    QTreeView tree;
    QColumnView columnView;

    list.setToolTip("QListView");
    table.setToolTip("QTableView");
    tree.setToolTip("QTreeView");
    columnView.setToolTip("QColumnView");

    list.setModel(model);
    table.setModel(model);
    tree.setModel(model);
    columnView.setModel(model);

    table.setColumnWidth(0, 200);
    table.setColumnWidth(1, 150);
    tree.header()->resizeSection(0, 200);
    tree.header()->resizeSection(1, 150);

    list.setSelectionModel(tree.selectionModel());
    table.setSelectionModel(tree.selectionModel());
    columnView.setSelectionModel(tree.selectionModel());
    table.setSelectionBehavior(QAbstractItemView::SelectRows);
    table.setSelectionMode(QAbstractItemView::SingleSelection);

    hsplitter.addWidget(&list);
    hsplitter.addWidget(&table);
    vsplitter.addWidget(&hsplitter);
    vsplitter.addWidget(&tree);
    vsplitter.addWidget(&columnView);
    vsplitter.setGeometry(300, 300, 500, 500);
    vsplitter.setWindowTitle("Multiple Views - Editable Model");

    QObjectList kids = vsplitter.children();
    foreach(QObject* optr, kids) {
        qDebug() << optr->metaObject()->className();
    }
    vsplitter.show();

    return a.exec();
}

