#include <QTextStream>
#include <QString>
#include <QFile>

QTextStream qtCout(stdout);
QTextStream qtCerr(stderr);

int main() {
  QString str, newstr;
  QTextStream strbuf(&str); //you have to associate the stream with the string
  int lucky = 7;
  float pi = 3.14;
  double e = 2.71;

  qtCout << "An in-memory stream" << endl;
  strbuf << "luckynumber: " << lucky << endl
         << "pi: " << pi << endl
         << "e: " << e << endl;

  qtCout << str;

  QFile data("mydata");
  data.open(QIODevice::WriteOnly);
  QTextStream out(&data);
  out << str;
  data.close();

return 0;

/*************************************/
  qtCout << "Read data from the file" << endl;
  if (data.open(QIODevice::ReadOnly)) {
    QTextStream in(&data);
    int lucky2;
    in >> newstr >> lucky2;
    if (lucky != lucky2)
      qtCerr << "ERROR! wrong " << newstr << lucky2 << endl;
    else
      qtCout << newstr << " OK" << endl;

    float pi2;
    in >> newstr >> pi2;
    if (pi != pi2)
      qtCerr << "ERROR! wrong " << newstr << pi2 << endl;
    else
      qtCout << newstr << " OK" << endl;

    double e2;
    in >> newstr >> e2;
    if (e != e2)
      qtCerr << "ERROR! wrong " << newstr << e2 << endl;
    else
      qtCout << newstr << " OK" << endl;

    data.close();
  }
  return 0;
}

