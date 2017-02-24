 #include "dialog.h"
#include <QApplication>
#include <QtGui>
#include <QProgressDialog>
#include <QFileDialog>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Dialog w;
//    w.show();

    QProgressDialog nonModal;
    nonModal.setWindowTitle("Non modal parent Dialog");
    nonModal.show();
    nonModal.connect(&nonModal,SIGNAL(finished()), &a, SLOT(quit()));

    QProgressDialog *nonModal2 = new QProgressDialog(&nonModal);
    nonModal2->setWindowTitle("Non modal child Dialog");

    QProgressDialog nonModal3;
    nonModal3.setWindowTitle("Non modal parentless Dialog");

    nonModal.resize(640,480);
    nonModal2->resize(320,200);
    nonModal3.resize(160,100);
    nonModal2->show();
    nonModal3.show();

    QFileDialog fileDialog(&nonModal, "Modal File Child Dialog");
    fileDialog.exec();  //similar to when entering an event loop - but for fileDialog
                        //modal dialog always appear in front of the other windows

    QMessageBox::question(0, QObject::tr("Modal parentless Dialog"),
                          QObject::tr("can you interact with the other dialogs now?"),
                          QMessageBox::Yes | QMessageBox::No);
                        //no need to call exec() here

    return a.exec();
}
