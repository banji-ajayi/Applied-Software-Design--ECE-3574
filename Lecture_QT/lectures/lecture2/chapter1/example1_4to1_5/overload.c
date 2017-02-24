#include <stdio.h>

void foo(int n) {
  printf("%d is a nice number.\n", n);
}

void foo(double f) {
  printf("%lf is a nice number.\n", f);
}

void foo(bool b) {
  printf("Always be %s to your bool.\n", (b?"true":"false"));
}

int main() {
  foo(5);
  foo(6.7);
  foo(true);
}

