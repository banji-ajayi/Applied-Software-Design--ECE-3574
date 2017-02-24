#ifndef REGISTERUSER_H
#define REGISTERUSER_H

#include <QWidget>
#include <QMessageBox>
#include <QCryptographicHash>
#include <classDefinitions.h>

extern QList<record> records;

namespace Ui {
class RegisterUser;
}

class RegisterUser : public QWidget
{
    Q_OBJECT
    
public:
    explicit RegisterUser(QWidget *parent = 0);
    ~RegisterUser();
    
signals:
    void okSignal();

private slots:
    void returnToMainLogin();

    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::RegisterUser *ui;
};

#endif // REGISTERUSER_H
