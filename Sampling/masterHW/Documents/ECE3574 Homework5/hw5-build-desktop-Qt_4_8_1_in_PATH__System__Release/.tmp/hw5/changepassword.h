#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QWidget>
#include <QMessageBox>
#include <classDefinitions.h>
#include <QCryptographicHash>

extern QList<record> records;

namespace Ui {
class ChangePassword;
}

class ChangePassword : public QWidget
{
    Q_OBJECT
    
public:
    QString mName;
    void setName(QString);
    explicit ChangePassword(QWidget *parent = 0);
    ~ChangePassword();
    
signals:

    void cancelSignal(QString);

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::ChangePassword *ui;
};

#endif // CHANGEPASSWORD_H
