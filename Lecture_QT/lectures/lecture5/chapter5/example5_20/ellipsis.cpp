#include <cstdarg>
#include <iostream>

using namespace std;

//NOTE in this example n specifies the number of parameters
double mean (int n ...) {
  va_list ap;
  double sum(0);
  int count(n);

  va_start(ap, n);
  for (int i =0; i < count; ++i) {
    sum += va_arg(ap, double);
  }
  va_end(ap);

  return (sum/count);
}

int main() {
  cout << mean(4, 11.3, 22.5, 33.7, 44.9) << endl;
  cout << mean(5, 13.4, 22.5, 123.45, 421.33, 2525.353) << endl;
}

