#ifndef LIFEMAINWINDOW_H
#define LIFEMAINWINDOW_H

#include "lifewidget.h"

#include <QMainWindow>
#include <QLayout>
#include <QTime>

namespace Ui {
class LifeMainWindow;
}

class LifeMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum {DEAD=0, ALIVE=1};
    explicit LifeMainWindow(QWidget *parent = 0);
    ~LifeMainWindow();
    static int neighborCount(const QImage& img, int x, int y);

private slots:
    void on_actionPopulate_Randomly_triggered();
    void on_actionStart_Stop_triggered(bool checked);
    void on_actionClear_triggered();
    void on_actionQuit_triggered();
    void on_actionAbout_Qt_triggered();
    void on_actionAbout_triggered();
    void calculate();

private:
    Ui::LifeMainWindow *ui;

    QSize m_boardSize;
    LifeWidget* m_lifeWidget;
    QImage m_current;
    int m_numGenerations;
    QTime m_timer;
    bool m_running;
};

#endif // LIFEMAINWINDOW_H
