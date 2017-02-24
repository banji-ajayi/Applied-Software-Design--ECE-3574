#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QSharedPointer>
#include <QSortFilterProxyModel>

#include <QMainWindow>

#include "playlistview.h"
#include "playlistsview.h"

#include "ui_mainwindow.h"
#include "metadatatablemodel.h"

class MetaData;
class SourceListModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    friend class PlayListView;
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static MainWindow* instance();

    void closeEvent(QCloseEvent* e);
protected:
    void changeEvent(QEvent * e);
private slots:
    void on_sourceListView_clicked(const QModelIndex &index);
    void on_lineEdit_textChanged(const QString &arg1);
    void on_actionRefresh_triggered();
    void on_actionRemove_triggered();
    void on_actionPaste_triggered();
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionAbout_triggered();
    void on_actionAboutQt_triggered();
    void on_actionQuit_triggered();
private:
    QSortFilterProxyModel* m_sfpm;
    MetaDataTableModel* m_currentModel;

    Ui::MainWindow *ui;

    SourceListModel* m_sourceListModel;
    QList<QSharedPointer<MetaData> > m_clippedList;
};

#endif // MAINWINDOW_H
