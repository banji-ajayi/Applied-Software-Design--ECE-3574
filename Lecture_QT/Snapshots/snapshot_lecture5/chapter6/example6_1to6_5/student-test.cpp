#include <QTextStream>
#include "student.h"

static QTextStream qtCout(stdout);

void finish(Student* student) {
  qtCout << "\nThe following "
         << student->getClassName()
         << " has applied for graduation.\n "
         << student->toString() << "\n";
}

int main() {
  Undergrad us("Frodo Baggins", 5562, "Ring Theory", 4, 1220);
  GradStudent gs("Bilbo Baggins", 3029, "History", 6, GradStudent::fellowship);

  qtCout << "Here is the data for the two students:\n";
  qtCout << us.getClassName() << endl << us.toString() << endl;
  qtCout << gs.getClassName() << endl << gs.toString() << endl;

  qtCout << "\nHere is what happens when they finish their studeies:\n";
  finish(&us);
  finish(&gs);
  return 0;
}

