#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>

#include <QTextStream>

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    QTextStream cout(stdout);

    int answer = 0;

    do {
        int factArg = 0;
        int fact(1);

        factArg = QInputDialog::getInt(0, "Factorial Calulcator",
                                       "Factorial of:", 1);
        cout << "User entered: " << factArg <<endl;

        int i=2;
        while (i<=factArg) {
            fact=fact*i;
            ++i;
        }

        QString response = QString("The factorial of %1 is %2.\n%3\n")
                .arg(factArg)
                .arg(fact)
                .arg("Do you want to compute another factorial?");
        answer = QMessageBox::question(0, "Play again?",
                                       response,
                                       QMessageBox::Yes | QMessageBox::No);
    } while (answer == QMessageBox::Yes);

    //return a.exec();
    return EXIT_SUCCESS;
}

