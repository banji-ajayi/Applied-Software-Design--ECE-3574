//#include <QCoreApplication>
#include <QApplication>

#include <QVector>
#include <QAbstractButton>
#include <QPushButton>
#include <QComboBox>
#include <QMenuBar>
#include <QCheckBox>
#include <QDateTimeEdit>
#include <QDoubleSpinBox>

#include <QDebug>

int processWidget(QWidget* wid) {
// this requires concepts presented in Chap 12
    if (wid->inherits("QAbstractSpinBox")) {
        QAbstractSpinBox* qasbp = static_cast<QAbstractSpinBox*>(wid);
        qasbp->setAlignment(Qt::AlignHCenter);
    }
// this requires concepts presented in Chapter 19 only
    else {
        QAbstractButton* buttonPtr = dynamic_cast<QAbstractButton*>(wid);
        if (buttonPtr) {
            buttonPtr->click();
            qDebug() << QString("I clicked on the %1 button:").arg(buttonPtr->text());
        }
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //QCoreApplication a(argc, argv);
    QVector<QWidget*> widvect;

    widvect.append(new QPushButton("Ok"));
    widvect.append(new QCheckBox("Checked"));
    widvect.append(new QComboBox());
    widvect.append(new QMenuBar());
    widvect.append(new QCheckBox("With Fries"));
    widvect.append(new QPushButton("Nooo!!!"));
    widvect.append(new QDateTimeEdit());
    widvect.append(new QDoubleSpinBox());
    foreach (QWidget* widpointer, widvect) {
        processWidget(widpointer);
    }

    return EXIT_SUCCESS; //return a.exec();
}

