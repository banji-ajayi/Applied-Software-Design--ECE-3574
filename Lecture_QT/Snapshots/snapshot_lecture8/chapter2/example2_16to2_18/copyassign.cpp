#include <iostream>
#include <string>

#include "fraction.h"

using namespace std;

int main() {
  Fraction twothirds(2,3);
  Fraction threequarters(3,4);
  Fraction acopy(twothirds);
  Fraction f4 = threequarters;
  cout << "\nafter declaration - " << Fraction::report() << endl;

  f4 = twothirds;
  cout << "\nbefore multiply - " << Fraction::report() << endl;

  f4 = twothirds.multiply(threequarters);
  cout << "\nafter multiply - " << Fraction::report() << endl;

  return 0;
}
  
