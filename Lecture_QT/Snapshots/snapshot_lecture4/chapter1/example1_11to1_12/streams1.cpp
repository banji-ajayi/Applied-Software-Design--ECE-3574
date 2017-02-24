#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main() {
  ostringstream strbuf;
  int lucky = 7;
  float pi = 3.14;
  double e = 2.71;

  cout << "An in-memory stream" << endl;
  strbuf << "luckynumber: " << lucky << endl
         << "pi: " << pi << endl
         << "e: " << e << endl;

  string strval = strbuf.str();
  cout << strval;

  ofstream outf;
  outf.open("mydata");
  outf << strval;
  outf.close();

/*************************************/
  cout << "Read data from the file" << endl;
  string newstr;
  ifstream inf;
  inf.open("mydata");
  if (inf) {
    int lucky2;
    inf >> newstr >> lucky2;
    if (lucky != lucky2)
      cerr << "ERROR! wrong " << newstr << lucky2  << endl;
    else
      cout << newstr << " OK" << endl;

    float pi2;
    inf >> newstr >> pi2;
    if (pi != pi2)
      cerr << "ERROR! wrong " << newstr << pi2  << endl;
    else
      cout << newstr << " OK" << endl;

    double e2;
    inf >> newstr >> e2;
    if (e != e2)
      cerr << "ERROR! wrong " << newstr << e2  << endl;
    else
      cout << newstr << " OK" << endl;

    inf.close();
  }
  return 0;
}

