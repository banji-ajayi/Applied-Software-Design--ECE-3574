#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <pthread.h>
#include <QTextStream>
#include <unistd.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void resetForms();

private slots:
    void slot_Update(bool);

    void on_exitButton_clicked();

    void on_actionExit_triggered();

    void on_actionStart_triggered();

    void on_actionStop_triggered();

    void on_startButton_clicked();

    void on_stopButton_clicked();

private:
    Ui::MainWindow *ui;
};

class myWidget: public QObject
{
    Q_OBJECT

public:
    void updateFunction(bool);

signals:
    void update(bool);
};


#endif // MAINWINDOW_H
