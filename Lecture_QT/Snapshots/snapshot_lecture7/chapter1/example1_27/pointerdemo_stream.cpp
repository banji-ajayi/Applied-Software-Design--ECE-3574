#include <iostream>

using namespace std;

int main() {
  int x = 4;
  int* px = 0;
  px = &x;
  cout << "x = " << x
       << " *px = " << *px
       << " px = " << px
       << " &px = " << &px << endl;
  x = x +1;
  cout << "x = " << x
       << " *px = " << *px
       << " px = " << px << endl;
  *px = *px +1;
  cout << "x = " << x
       << " *px = " << *px
       << " px = " << px << endl;
  return 0;
}
