#include <iostream>
#include "template.h"

using namespace std;

int main() {
  Fraction<double> dfract;
  Fraction<int> ifract;
  dfract.set(3.2, 4.3);
  ifract.set(11, 12);
  
  cout << "The double fraction is: " << dfract.toString() << endl;
  cout << "The int fraction is: " << ifract.toString() << endl;

  Fraction<double> dsquare = dfract.square();
  cout << "The double square fraction is: " << dsquare.toString() << endl;

  return 0;
}

