#ifndef USERWELCOME_H
#define USERWELCOME_H

#include <QDialog>

namespace Ui {
class UserWelcome;
}

class UserWelcome : public QDialog
{
    Q_OBJECT

public:
    QString username;
    explicit UserWelcome(QWidget *parent = 0);
    void setUsername(QString name);
    ~UserWelcome();

signals:
    void changePassword();
    void startGame();
    void quitApplication();

private slots:
    void on_changepassButton_clicked();
    void on_startButton_clicked();
    void on_exitButton_clicked();

private:
    Ui::UserWelcome *ui;
};

#endif // USERWELCOME_H
