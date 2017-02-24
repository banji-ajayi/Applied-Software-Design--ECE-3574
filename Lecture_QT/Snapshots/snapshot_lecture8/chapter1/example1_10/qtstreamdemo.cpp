#include <QTextStream>

QTextStream qtCin(stdin);
QTextStream qtCout(stdout);
QTextStream qtCerr(stderr);

int main() {
  int num1(1234), num2(2345);
  qtCout << oct << num2 << '\t'
       << hex << num2 << '\t'
       << dec << num2 << endl;

  qtCout << (num1 < num2) << '\t'
       << bin << (num1 < num2) << endl;

  double dub(1357);
  qtCout << dub << '\t'
       << forcesign << dub << '\t'
       << forcepoint << dub << '\t'
       << showbase << dub << endl;

  dub = 1234.5678;
  qtCout << dub << '\t'
       << fixed << dub << '\t'
       << scientific << dub << '\t'
       << noforcesign << dub << endl; //this changed from C++ SL to Qt

  return 0;
}
