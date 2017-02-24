#include <iostream>

using namespace std;

class Foo {
public:
  void operator() (int i)
    { cout << "Foo " << i << endl; }
};

int main() {
  Foo foo;
  foo(123); //functor
}

