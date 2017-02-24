#include <iostream>

using namespace std;

int& maxi(int& x, int& y) {
  return (x > y) ? x : y;
}

int main() {
  int a =10, b =20;
  cout << "a: " << a << " b: " << b << endl;

//GOAL: assign 5 to the max(a,b)
/*  if ( a > b )
    a = 5;
  else
    b = 5; */

  maxi(a, b) = 5;
  cout << "a: " << a << " b: " << b << endl;

  maxi(a, b) += 6;
  cout << "a: " << a << " b: " << b << endl;

  ++maxi(a, b);
  cout << "a: " << a << " b: " << b << endl;
  
  return 0;
}

