#ifndef USERREGISTER_H
#define USERREGISTER_H

#include <QDialog>
#include <QMessageBox>
#include <QCryptographicHash>
#include "recordhelper.h"

extern QList<Record> myRecords;

namespace Ui {
class UserRegister;
}

class UserRegister : public QDialog
{
    Q_OBJECT

public:
    explicit UserRegister(QWidget *parent = 0);
    ~UserRegister();

signals:
    void registerComplete();

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::UserRegister *ui;
};

#endif // USERREGISTER_H
