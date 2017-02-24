//#include "mainwindow.h"

#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QAction>
#include <QDebug>
#include <QApplication>
#include <QToolBar>
#include <QMessageBox>
#include <QActionGroup>

#include "study.h"

int main (int argc, char** argv) {
    QApplication app(argc, argv);
    Study study;
    study.show();
    return app.exec();
}
