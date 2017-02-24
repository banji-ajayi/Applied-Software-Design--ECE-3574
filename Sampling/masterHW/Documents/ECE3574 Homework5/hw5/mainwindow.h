#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainlogin.h"
#include "registeruser.h"
#include "changepassword.h"
#include "tictactoe.h"
#include "welcomeuser.h"
#include <classDefinitions.h>
#include <QDataStream>

extern QList<record> records;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QString mName;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void hideAllWidgets();
    
private slots:

    void displayWelcome(QString);

    void displayMainLogin();

    void displayRegister();

    void displayChangePassword(QString);

    void displayTicTacToe(QString);

    void on_actionRegister_User_triggered();

    void on_actionLogout_triggered();

    void on_actionExit_triggered();

    void on_actionNew_game_triggered();

    void on_actionEnd_game_triggered();

    void on_actionChange_Password_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
