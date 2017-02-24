#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QClipboard>

class QAction;
class QLabel;
class QMenu;
class QTextEdit;
class QStackedWidget;

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();

    void closeEvent(QCloseEvent *event);

protected slots:
    virtual void documentWasModified();
    virtual QWidget* initialWidget() const;

    virtual void clipboardChanged(QClipboard::Mode);

protected:
    virtual void createStatusBar();
    virtual bool maybeSave();
    virtual void readSettings();
    virtual void writeSettings();

    QStackedWidget* m_StackedWidget;
    QTextEdit* m_TextEdit;
    QLabel* m_ModLabel;
};

#endif // MAINWINDOW_H
