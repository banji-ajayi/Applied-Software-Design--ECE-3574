#include <QTextStream>
#include <QString>

int main() {
  const char*charstr = "this is a long string";
  QTextStream cout(stdout);
  QString str = charstr;

  cout << str << endl;
  cout << "\nA\tb\\c\'d\"" << endl;
  return 0;
}
