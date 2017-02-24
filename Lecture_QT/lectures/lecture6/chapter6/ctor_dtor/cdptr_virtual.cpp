/*
 * ctor dtor inheritance and polym example
 */
#include <iostream>

using namespace std;

class A {
public:
  A() {
  cout << "A ctor" << endl; }
  virtual ~A() {
  cout << "A dtor" << endl; }
};
class B : public A {
public:
  B() {
  cout << "B ctor" << endl; }
  ~B() {
  cout << "B dtor" << endl; }
};
class C : public B {
public:
  C() {
  cout << "C ctor" << endl; }
  ~C() {
  cout << "C dtor" << endl; }
};

int main() {
  A* a = new A();
  B* b = new B();
  C* c = new C();
  cout << "----------------" << endl;

  delete a;
  delete b;
  cout << "================" << endl;
  
  a = c;
  delete a;
}

