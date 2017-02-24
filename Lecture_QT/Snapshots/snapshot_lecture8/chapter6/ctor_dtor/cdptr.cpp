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

  delete b;
  cout << "****************" << endl; 
  delete a;
  cout << "****************" << endl; 
  delete c;
  cout << "****************" << endl; 
 //uncomment these!
}

//when you allocate variables/objects on the heap (new and delete) if you don't remove them from the memory no one will do it for you! Always remember to call delete if you are not planning to use such objects later!

