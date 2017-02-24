
#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QString>

class Dialogs : public QMainWindow {
  Q_OBJECT
public:
  Dialogs();
private slots:
  void askQuestion();
  void askDumbQuestion();
private:
  QString answer;
};

