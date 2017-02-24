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

  return 0;
}

