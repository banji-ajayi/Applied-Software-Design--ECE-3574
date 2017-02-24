/*
 * ctor dtor inheritance and polym example
 */
#include <iostream>

using namespace std;

class A {
public:
  A() {
  cout << "A ctor" << endl; }
  ~A() {
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
  delete a; //WARNING!!! I didn't delete a C object! Memory leak?
  cout << "================" << endl;
}

//note that we don't have anything virtual here. However, for the sake of learning polymorphism we want to delete a and b and make a pointing to c (a C object!). Due to inheritance C is an A object (because A<-B<-c), therefore is legal in C++. However, when you call the last "delete a" only the destructor A is called.
