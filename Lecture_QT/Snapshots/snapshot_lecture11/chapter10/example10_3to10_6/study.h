#ifndef STUDY
#define STUDY

#include <QMainWindow>
class QAction;
class QActionGroup;

class Study : public QMainWindow {
    Q_OBJECT
public:
    explicit Study(QWidget* parent=0);
public slots:
    void actionEvent(QAction *);
private:
    QActionGroup* actionGroup;
    QToolBar* toolbar;

    QAction* useTheForce;
    QAction* useTheDarkSide;
    QAction* studyWithObiWan;
    QAction* studyWithYoda;
    QAction* studyWithEmperor;
    QAction* fightYoda;
    QAction* fightDarthVader;
    QAction* fightObiWan;
    QAction* fightEmperor;
protected:
    QAction* addChoice(QString name, QString text);
};

#endif // STUDY

