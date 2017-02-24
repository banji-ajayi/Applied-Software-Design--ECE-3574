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
  cout << "----------------" << endl;
  B* b = new B();
  cout << "----------------" << endl;
  C* c = new C();
  cout << "----------------" << endl << endl;

  delete a;
  cout << "****************" << endl; 
  delete b;
  cout << "****************" << endl; 
  
  a = c;
  delete a;
  cout << "================" << endl;
}

// having virtual destructors solve the problem

