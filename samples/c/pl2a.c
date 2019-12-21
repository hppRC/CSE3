#include <stdio.h>

int n;

int fact(int n) {
  if (n <= 0) {
    return 1;
  } else {
    return fact(n - 1) * n;
  }
}

int main() {
  scanf("%d\n", &n);
  printf("%d\n", fact(n));

  return 0;
}