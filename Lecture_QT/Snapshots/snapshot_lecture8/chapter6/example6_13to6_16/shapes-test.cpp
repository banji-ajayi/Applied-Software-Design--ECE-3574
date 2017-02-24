#include <QString>
#include "shapes.h"
#include <QTextStream>

QTextStream qtCout(stdout);

void showNameAndArea(Shape* pshp) {
  qtCout << pshp->getName()
    << " " << pshp->getDimensions()
    << " area= " << pshp->area() << endl;
}

int main() {
  //Shape shp; //NOTE compile time error because it is an abstract class

  Rectangle rectangle(4.1, 5.2);
  Square square(5.1);
  Circle circle(6.1);

  qtCout << "This program uses hierachies for Shapes" << endl;
  showNameAndArea(&rectangle);
  showNameAndArea(&square);
  showNameAndArea(&circle);

  return 0;
}
