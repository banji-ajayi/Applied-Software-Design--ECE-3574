#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mylistmodel.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void clearUI();
    void updateEmiter(bool signalUI);
    ~MainWindow();

signals:
    void updateUI(bool);

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_exitButton_clicked();

    void on_actionStart_triggered();
    void on_actionStop_triggered();
    void on_actionExit_triggered();

    void refreshUI(bool signalIn);

private:
    Ui::MainWindow *ui;
    myListModel *listModel;
};

#endif // MAINWINDOW_H
