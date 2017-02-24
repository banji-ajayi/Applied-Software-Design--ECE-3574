/*
 * ctor dtor inheritance and polym example
 */
#include <iostream>

using namespace std;

class A {
public:
  //virtual A() { //ERROR constructor cannot be declared virtual
  A() {
  cout << "A ctor" << endl; }
  virtual ~A() {
  cout << "A dtor" << endl;
  cout << "++++++++++++++++" << endl; }
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
  A a;
  cout << "----------------" << endl;
  B b;
  cout << "----------------" << endl;
  C c;
  cout << "----------------" << endl << endl;
}

// There is no concept of virtual constructor, constructor are always chained (eventually by the compiler). Differently destructors don't have to be chained, therefore they can be virtual, as in the example.
