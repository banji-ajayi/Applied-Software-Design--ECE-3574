#include <iostream>

using namespace std;

class A {
public:
  virtual void foo() {
  //void foo() {
    cout << "A's foo()" << endl;
  }
};

class B : public A {
public:
  void foo() {
    cout << "B's foo()" << endl;
  }
};

int main() { 
  B bobj;
  A *aptr = &bobj;
  aptr->foo();
}
