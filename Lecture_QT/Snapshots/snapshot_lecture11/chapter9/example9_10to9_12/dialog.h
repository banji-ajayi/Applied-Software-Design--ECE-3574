#ifndef DIALOG_H
#define DIALOG_H

#include <QString>
#include <QDate>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Product {
public:
    QString m_name;
    QString m_description;
    double m_price;
    QDate m_dateValid;
};

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void setModel(Product* model);

private slots:
    void on_buttonBox_accepted();
    void commit();
    void update();

private:
    Ui::Dialog *ui;
    Product* m_model;
};

#endif // DIALOG_H
