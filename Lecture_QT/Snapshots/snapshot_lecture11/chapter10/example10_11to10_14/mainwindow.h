#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QUndoStack>
#include <QMainWindow>

class QLabel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void displayImage(const QImage& img);

private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionClose_triggered();
    void on_actionQuit_triggered();
    void on_undoButton_clicked();
    void on_redoButton_clicked();
    void on_pushButton_3_clicked();
    void on_saveButton_clicked();
    void on_openButton_clicked();
    void on_verticalMirrorButton_clicked();
    void on_horizontalMirrorButton_clicked();
    void on_adjustColorButton_clicked();

private:
    Ui::MainWindow *ui;
    QLabel* m_ImageDisplay;
    QImage m_Image;
    QUndoStack m_Stack;
};

#endif // MAINWINDOW_H
