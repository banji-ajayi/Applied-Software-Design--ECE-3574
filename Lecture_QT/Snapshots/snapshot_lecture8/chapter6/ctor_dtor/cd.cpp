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

//local variables/classes, which are allocated on the stack are automatically deallocated by the compiler at the end of the function (i.e., when the function returns) - the programmer doesn't have to write code for that. The compiler calls the destructor for each local variable/object in the inverse order of declaration. Destructor are also called in the inverse order.
