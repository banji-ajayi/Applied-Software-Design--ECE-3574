#ifndef WELCOMEUSER_H
#define WELCOMEUSER_H

#include <QWidget>
#include <classDefinitions.h>
#include <QString>

namespace Ui {
class WelcomeUser;
}

class WelcomeUser : public QWidget
{
    Q_OBJECT
    
public:
    QString mName;
    void setName(QString);
    explicit WelcomeUser(QWidget *parent = 0);
    ~WelcomeUser();

signals:
    void exitSignal();
    void changePassSignal(QString);
    void startGameSignal(QString);

private slots:
    void on_changePassButton_clicked();

    void on_startButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::WelcomeUser *ui;
};

#endif // WELCOMEUSER_H
