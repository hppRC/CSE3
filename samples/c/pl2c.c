#include <stdio.h>

int n, sum;

void result(int n) {
  sum = sum + n;
  return;
}

void result() {
  printf("%d\n", sum);
  return;
}

int main() {
  n = 10;
  sum = 0;
  while (n > 0) {
    result(n);
    n = n - 1;
  }
  result();

  return 0;
}