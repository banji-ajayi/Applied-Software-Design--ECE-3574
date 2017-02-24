#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QList>

#include "tictactoe.h"
#include "userlogin.h"
#include "userwelcome.h"
#include "recordhelper.h"
#include "userregister.h"
#include "changepassword.h"

extern QList<Record> myRecords;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString username;
    explicit MainWindow(QWidget *parent = 0);
    void clearForms();
    ~MainWindow();

private slots:
    void displayGame();
    void displayLogin();
    void displayRegister();
    void quitApplication();
    void displayPassword();
    void displayWelcome(QString name);
    void on_actionRegister_User_triggered();
    void on_actionLogout_User_triggered();
    void on_actionExit_triggered();
    void on_actionNew_Game_triggered();
    void on_actionEnd_Game_triggered();
    void on_actionChange_Password_triggered();

private:
    Ui::MainWindow *ui;
    TicTacToe *gameDialog;
    UserLogin *loginDialog;
    UserWelcome *welcomeDialog;
    UserRegister *registerDialog;
    ChangePassword *passwordDialog;
};

#endif // MAINWINDOW_H
