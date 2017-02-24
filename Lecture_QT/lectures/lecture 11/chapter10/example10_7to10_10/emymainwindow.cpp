
#include <QtGui>
#include <QAction>
#include <QLabel>
#include <QTextEdit>
#include <QStackedWidget>
#include <QClipboard>

#include <QStatusBar>
#include <QDockWidget>
#include <QSettings>
#include <QMessageBox>
#include <QStringList>

#include "emymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_StackedWidget = new QStackedWidget();
    m_TextEdit = new QTextEdit(m_StackedWidget);
    QDockWidget* mainDock = new QDockWidget("Text Editor");
    mainDock->setWidget(m_TextEdit);
    setCentralWidget(mainDock);

    createStatusBar();
    readSettings();
    connect(m_TextEdit->document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));
    setWindowTitle(tr("Application"));

    connect(qApp->clipboard(), SIGNAL(changed(QClipboard::Mode)),
            this, SLOT(clipboardChanged(QClipboard::Mode)));
}

MyMainWindow::~MyMainWindow()
{
}

bool MyMainWindow::maybeSave() {
    if (m_TextEdit->document()->isModified()) {
        int ret = QMessageBox::warning(this, tr("Application"),
                                       tr("The document has been modified.\nDo you want to save your changes?"),
                                       QMessageBox::Yes | QMessageBox::Default,
                                       QMessageBox::No,
                                       QMessageBox::Cancel | QMessageBox::Escape);
        if (ret == QMessageBox::Yes)
            return true;
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}

void MyMainWindow::closeEvent(QCloseEvent* event) {
    if (maybeSave()) {
        writeSettings();
        event->accept();
    }
    else {
        event->ignore();
    }
}

void MyMainWindow::readSettings() {
    QSettings settings;
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QPoint(400, 400)).toSize();
    QByteArray state = settings.value("state", QByteArray()).toByteArray();
    restoreState(state)    ;
    resize(size);
    move(pos);
}

void MyMainWindow::writeSettings() {
    QSettings settings;
    settings.setValue("pos", pos());
    settings.setValue("size", size());
    settings.setValue("state", saveState());
}

void MyMainWindow::createStatusBar() {
    m_ModLabel = new QLabel(tr("MOD?"));
    m_ModLabel->setAlignment(Qt::AlignHCenter);
    m_ModLabel->setMinimumSize(m_ModLabel->sizeHint());
    m_ModLabel->clear();

    statusBar()->addWidget(m_ModLabel, 0);
}

void MyMainWindow::documentWasModified() {
    m_ModLabel->setText(tr("MOD"));
}

QWidget* MyMainWindow::initialWidget() const {
    return m_StackedWidget->widget(0);
}


void MyMainWindow::clipboardChanged(QClipboard::Mode) {
    QStringList s1;
    QClipboard *cb = qApp->clipboard();
    const QMimeData *md = cb->mimeData();
    s1 << "Formats: " + md->formats().join(",");
    foreach(QString format, md->formats()) {
        QByteArray ba = md->data(format);
        s1 << " " + format + ": " + QString(ba);
    }
    m_TextEdit->setText(s1.join("\n"));
}
