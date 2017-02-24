#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QCheckBox>

class mainWindow : public QWidget {
    Q_OBJECT

public:
    mainWindow();
    QStringList getFileStringList(QFile&);

protected slots:
    void buttonPress(int);

private:
    QPushButton *buttons[4];
    QTextEdit *textEdit;
    QCheckBox *prompt;
    QStringList dontDisplayMessages;

};

#endif // MAINWINDOW_H
