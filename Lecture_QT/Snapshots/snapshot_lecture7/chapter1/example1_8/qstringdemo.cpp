#include <QString>
#include <QTextStream>

QTextStream qtCout(stdout);
QTextStream qtCin(stdin);

int main() {
  QString s1("This "), s2("is a "), s3("string."); //initialization

  s1 += s2; //append

  QString s4 = s1 + s3; //concatenation
  qtCout << s4 << endl;

  QString s5("The length of that string is: "); //initialization
  qtCout << s5 << s4.length() << " chars." << endl; //len

  qtCout << "Enter a sentence: " << endl;
  s2 = qtCin.readLine(); //read input from console (cin) 

  qtCout << "Your sentence: \n" << s2 << endl;
  qtCout << "The length of your string is: " << s2.length() << endl;
  return 0;
}
