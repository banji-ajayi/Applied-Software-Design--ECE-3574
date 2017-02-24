#include "complexEz.h"
#include <iostream>

using namespace std;

int main() {
  Complex c1(3.4, 5.6);
  Complex c2(7.8, 1.2);
  cout << c1.toString() << " + " << c2.toString() << " = " << (c1 + c2).toString() << endl;
//  cout << c1.toString() << " - " << c2.toString() << " = "
//       << (c1 - c2).toString() << endl; //NOTE this is not implemented operator- WHAT THEY RETURN IS DIFFERENT

  c1 += c2;
  c2 -= c1;
  cout << "c1: " << c1.toString() << endl;
  cout << "c2: " << c2.toString() << endl;

  return 0;
}

