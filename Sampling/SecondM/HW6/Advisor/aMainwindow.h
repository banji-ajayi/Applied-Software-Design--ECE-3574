#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSignalMapper>
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QStringList>
#include <QTextStream>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QCheckBox>
#include <QDebug>
#include <QFile>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    QStringList getLinesWithBreaks(QFile&myFile);

protected slots:
    void buttonEvent(int button);

private:
    QTextEdit *myTextEdit;
    QCheckBox *prompt;
    QStringList alreadyDisplayed;
};

#endif // MAINWINDOW_H
