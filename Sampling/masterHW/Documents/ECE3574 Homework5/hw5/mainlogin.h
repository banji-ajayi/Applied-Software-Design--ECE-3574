#ifndef MAINLOGIN_H
#define MAINLOGIN_H

#include <QWidget>
#include <QList>
#include <QFile>
#include <classDefinitions.h>
#include <QTextStream>
#include <QCryptographicHash>

extern QList<record> records;

namespace Ui {
class mainLogin;
}

class mainLogin : public QWidget
{
    Q_OBJECT
    
public:
    explicit mainLogin(QWidget *parent = 0);
    ~mainLogin();
    void readFile();

signals:
    void goodLogin(QString);
    void exitSignal();
    
private slots:

    void goodLoginSlot(QString);

    void on_login_clicked();

    void on_exit_clicked();

private:
    Ui::mainLogin *ui;

};

#endif // MAINLOGIN_H
