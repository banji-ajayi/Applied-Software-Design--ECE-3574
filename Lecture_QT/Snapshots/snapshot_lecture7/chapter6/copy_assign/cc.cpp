/*
 * copy constructor example
 */
#include <iostream>

using namespace std;

class A {
public:
  //virtual A() { //ERROR constructor cannot be declared virtual
  A() {
  cout << "A ctor" << endl; }
  //virtual A(const A& a) { //ERROR constructor cannot be declared virtual
  A(const A& a) {
  cout << "A cc" << endl; }
  virtual ~A() {
  /* cout << "A dtor" << endl; */ }
};
class B : public A {
public:
  B() {
  cout << "B ctor" << endl; }
  B(const B& b) {
  cout << "B cc" << endl; }
  ~B() {
  /* cout << "B dtor" << endl; */ }
};
class C : public B {
public:
  C() {
  cout << "C ctor" << endl; }
  C(const C& c) {
  cout << "C cc" << endl; }
  ~C() {
  /* cout << "C dtor" << endl; */ }
};

int main() {
  A a;
  cout << "----------------" << endl;
  B b;
  cout << "----------------" << endl;
  C c;
  cout << "----------------" << endl << endl;

  A aa = a;
  cout << "================" << endl;
  B bb = b;
  cout << "================" << endl;
  C cc = c;
  cout << "================" << endl;
}

