
#include <iostream>
#include "fraction.h"
#include "complex.h"

using namespace std;

template <class T>
T power (T a, int exp) {
  T ans =a;
  while (--exp >0)
    ans *=a;
  return (ans);
}
/* NOTE
 * even if the template parameter is "class T" T can be a class
 * or a primitive type - see the example below
 */

int main() {
  Complex z(3,4), z1;
  Fraction f(5,6), f1;
  int n(19);

  z1 =power(z, 3);
  cout << "z1 " << z1.toString() << endl;
  f1 =power(f, 4);
  cout << "f1 " << f1.toString() << endl;

  z1 =power<Complex>(n, 4);
  cout << "z1 " << z1.toString() << endl;
  z1 =power(n, 5);
  cout << "z1 " << z1.toString() << endl;

  return 0;
}
