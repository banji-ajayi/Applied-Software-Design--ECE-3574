#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QDialog>
#include <QString>
#include <QFile>
#include <QApplication>
#include <QTextStream>
#include <QCryptographicHash>
#include <QMessageBox>
#include "recordhelper.h"

extern QList<Record> myRecords;

namespace Ui {
class UserLogin;
}

class UserLogin : public QDialog
{
    Q_OBJECT

public:
    explicit UserLogin(QWidget *parent = 0);
    bool checkCredentials();
    ~UserLogin();

signals:
    void loginComplete(QString);
    void quitApplication();

private slots:
    void on_exitButton_clicked();
    void on_loginButton_clicked();

private:
    Ui::UserLogin *ui;
    QString username;
    QString password;
};

#endif // USERLOGIN_H
