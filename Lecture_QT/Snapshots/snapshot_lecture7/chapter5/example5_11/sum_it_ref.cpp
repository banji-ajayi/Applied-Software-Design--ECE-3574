#include <iostream>

using namespace std;

int sum_it_ref(int& num) { 
  int sum =0;
  for (; num; --num)
    sum += num;
  return sum;
}

int main() {
  int n =10;
  cout << n << endl;

  cout << sum_it_ref(n) << endl;
  cout << n << endl;

  return 0;
}

