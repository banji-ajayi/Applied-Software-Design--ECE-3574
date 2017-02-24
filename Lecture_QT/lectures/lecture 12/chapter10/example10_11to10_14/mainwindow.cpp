
#include <QtGui>
#include <QLabel>
#include <QImage>
#include <QUndoStack>

#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "image-manip.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_ImageDisplay(new QLabel(this)), m_Image(QImage())
{
    ui->setupUi(this);
    m_ImageDisplay->setMinimumSize(640,480);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayImage(const QImage &img) {
    m_ImageDisplay->setPixmap(QPixmap::fromImage((img)));
}


void MainWindow::on_actionOpen_triggered()
{
    m_Image.load(QFileDialog::getOpenFileName());
    displayImage(m_Image);
}

void MainWindow::on_actionSave_triggered()
{
    on_saveButton_clicked();
}

void MainWindow::on_actionClose_triggered()
{
    m_ImageDisplay->clear();
    m_Image.allGray();
}

void MainWindow::on_actionQuit_triggered()
{
    on_pushButton_3_clicked();
}

void MainWindow::on_undoButton_clicked()
{
    m_Stack.undo();
    displayImage(m_Image);
}

void MainWindow::on_redoButton_clicked()
{
    m_Stack.redo();
    displayImage(m_Image);
}

void MainWindow::on_pushButton_3_clicked()
{
    QApplication::quit();
}

void MainWindow::on_saveButton_clicked()
{
    QString filename(QFileDialog::getSaveFileName());
    m_Image.save(filename);
}

void MainWindow::on_openButton_clicked()
{
    on_actionOpen_triggered();
}

void MainWindow::on_verticalMirrorButton_clicked()
{
    MirrorPixels* mp = new MirrorPixels(m_Image, false);
    m_Stack.push(mp);
    displayImage(m_Image);
}

void MainWindow::on_horizontalMirrorButton_clicked()
{
    MirrorPixels* mp = new MirrorPixels(m_Image, true);
    m_Stack.push(mp);
    displayImage(m_Image);
}

void MainWindow::on_adjustColorButton_clicked()
{
    double radj(ui->redSpin->value()),
           gadj(ui->greenSpin->value()),
           badj(ui->blueSpin->value());
    AdjustColors* ac = new AdjustColors(m_Image, radj, gadj, badj);
    m_Stack.push(ac);
    displayImage(m_Image);
}


