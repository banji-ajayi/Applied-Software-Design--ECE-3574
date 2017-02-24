#include <iostream>

using namespace std;

void messAround(int* ptr) {
  *ptr = 32;
  ptr = 0;
}

int main() { 
  int n(12);
  int* pn(&n); //NOTE &n ampersand is the address-of operator
  cout << "n = " << n << "\tpn = " << pn << endl;

  messAround(pn);
  cout << "n = " << n << "\tpn = " << pn << endl;

  return 0;
}

