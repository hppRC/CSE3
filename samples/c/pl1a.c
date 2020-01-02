#include <stdio.h>

int n, temp;

void fact(int n) {
  if (n <= 1) {
    temp = 1;
  } else {
    fact(n - 1);
    temp = temp * n;
  }
  return;
}

int main() {
  scanf("%d\n", &n);
  fact(5);
  printf("%d\n", temp);
  return 0;
}