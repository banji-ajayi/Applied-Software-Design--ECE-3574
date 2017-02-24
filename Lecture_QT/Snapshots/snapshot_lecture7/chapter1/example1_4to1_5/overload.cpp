#include  <iostream>

using namespace std;

void foo(int n) {
  cout << n << " is a nice number." << endl;
}

void foo(double f) {
  cout << f << " is a nice number." << endl;
}

void foo(bool b) {
  cout << "Always be " << (b?"true":"false") << " to your bool." << endl;
}

int main() {
  foo(5);
  foo(6.7);
  foo(true);
}

