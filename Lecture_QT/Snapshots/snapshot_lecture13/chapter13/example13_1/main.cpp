
#include "mainwindow.h"
#include <QApplication>
#include <QtGui>

#include <QHeaderView>
#include <QTreeView>
#include <QFileSystemModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTreeView tree;
    QFileSystemModel model;

    model.setRootPath("/");
    tree.setModel(&model);
    tree.setSortingEnabled(true);
    tree.header()->setResizeContentsPrecision(QHeaderView::ResizeToContents);
    tree.resize(640, 480);
    tree.show();

    return a.exec();
}
