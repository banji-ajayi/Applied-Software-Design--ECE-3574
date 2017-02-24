#include <QtGui>
#include <QHeaderView>

#include "playlistview.h"
#include "mainwindow.h"

PlayListView::PlayListView(QWidget *parent)
    : QTableView(parent) {
    QHeaderView* hv = horizontalHeader();
    hv->setResizeContentsPrecision(QHeaderView::ResizeToContents);

    MainWindow* mw = MainWindow::instance();
    addAction(mw->ui->actionCopy);
    addAction(mw->ui->actionPaste);
    addAction(mw->ui->actionCut);
    addAction(mw->ui->actionRemove);
    addAction(mw->ui->actionRefresh);
    setContextMenuPolicy(Qt::ActionsContextMenu);
}

void PlayListView::dropEvent(QDropEvent *event) {
    model()->dropMimeData(event->mimeData(), event->dropAction(), -1, -1, QModelIndex());
    event->accept();
}

void PlayListView::startDrag(Qt::DropActions supportedActions) {
    QModelIndexList indexes = selectionModel()->selectedRows();
    if (indexes.count() > 0) {
        QMimeData * data = model()->mimeData(indexes);
        if (!data)
            return;
        QDrag * drag = new QDrag(this);
        drag->setMimeData(data);
        Qt::DropAction defaultDropAction = Qt::IgnoreAction;
        drag->exec(supportedActions, defaultDropAction);
    }
}
