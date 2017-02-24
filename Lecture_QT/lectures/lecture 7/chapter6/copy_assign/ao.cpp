/*
 * assignment operator example
 */
#include <iostream>

using namespace std;

class A {
public:
  A() {
  cout << "A ctor" << endl; }
  A(const A& a) {
  cout << "A cc" << endl; }
/* assignment operator **************/
  virtual A& operator= (const A& a) {
  cout << "A ao" << endl; 
  return *this; }
/************************************/
  virtual ~A() { }
};
class B : public A {
public:
  B() {
  cout << "B ctor" << endl; }
  B(const B& b) {
  cout << "B cc" << endl; }
/* assignment operator **************/
  B& operator= (const B& b) {
  cout << "B ao" << endl; 
  return *this; }
/************************************/
  ~B() { }
};
class C : public B {
public:
  C() {
  cout << "C ctor" << endl; }
  C(const C& c) {
  cout << "C cc" << endl; }
/* assignment operator **************/
  C& operator= (const C& c) {
  cout << "C ao" << endl; 
  return *this; }
/************************************/
  ~C() { }
};

int main() {
  A a;
  cout << "----------------" << endl;
  B b;
  cout << "----------------" << endl;
  C c;
  cout << "----------------" << endl << endl;

  A aa; aa = a;
  cout << "================" << endl;
  B bb; bb = b;
  cout << "================" << endl;
  C cc; cc = c;
  cout << "================" << endl; 
}

