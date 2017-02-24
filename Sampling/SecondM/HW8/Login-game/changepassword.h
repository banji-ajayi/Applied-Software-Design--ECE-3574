#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>
#include <QMessageBox>
#include <QCryptographicHash>
#include "recordhelper.h"

extern QList<Record> myRecords;

namespace Ui {
class ChangePassword;
}

class ChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePassword(QWidget *parent = 0);
    QString username;
    void setUsername(QString name);
    ~ChangePassword();

signals:
    void changePassComplete(QString);

private slots:
    void on_cancelButton_clicked();
    void on_okButton_clicked();

private:
    Ui::ChangePassword *ui;
};

#endif // CHANGEPASSWORD_H
