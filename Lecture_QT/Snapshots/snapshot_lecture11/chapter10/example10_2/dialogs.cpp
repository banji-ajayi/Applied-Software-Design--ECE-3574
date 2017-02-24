
/* NOTE that you cannot create a single .cpp file otherwise the MOC system will not compile */

#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QAction>
#include <QDebug>
#include <QApplication>

#include "dialogs.h"

Dialogs::Dialogs() {
  QWidget::setWindowTitle("Gullap Poll");
  QWidget::move(300,300);
  
  QMenu* menu = new QMenu(tr("&Questions"), this);
  QMainWindow::menuBar()->addMenu(menu);

  menu->addAction(tr("&Ask question"), this, SLOT(askQuestion()), tr("Alt+A"));
  menu->addAction(tr("Ask a &dumb question"), this, SLOT(askDumbQuestion()), tr("Alt+D"));
}

void Dialogs::askQuestion() {
  bool done = false;
  QString q1(tr("Who was Canadian Prime Minister in 1847?")),
          a0("John A. MacDonald"),
          a1("Alexander Mackenzie"),
          a2("Sir Wilfred Laurier");
  while (!done) {
    int ans = QMessageBox::question(this, tr("Difficult Question"),
                           q1, a0, a1, a2, 0, -1);
    if (ans < 0)
      return;
    switch (ans) {
    case 0:
      answer =a0;
      break;
    case 1:
      answer =a1;
      break;
    case 2:
      answer =a2;
      return; // This is different from the book example - only to semplify this example
      break;
    }
  }
} // There was no prime minister until 1867

void Dialogs::askDumbQuestion() {
  QMessageBox::question(this, tr("Political question"),
               tr("What kind of political animal are you?"),
               tr("donkey"), tr("elephant"), tr("penguin"),
               1, -1);
}

int main (int argc, char** argv) {
  QApplication a(argc, argv);
  Dialogs* awd = new Dialogs();
  awd->show();
  a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
  return a.exec();
}

