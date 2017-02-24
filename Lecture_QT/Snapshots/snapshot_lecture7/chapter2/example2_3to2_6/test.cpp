#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
/* // block scope example
  const int DASHES = 30;
  {
    int i; // i is declared inside this block
    for (i = 0; i < DASHES; ++i)
      cout << "=";
    cout << endl;
  }
  cout << "i = " << i << endl; // error - i is not visible outside the block
*/

  Fraction f1, f2;
  f1.set(3, 4);
  f2.set(11, 12);
  //f2.m_Numerator = 12; // error

  cout << "The first fraction is: " << f1.toString() << endl;
  cout << "The second fraction is: " << f2.toDouble() << endl;

  return 0;
}

