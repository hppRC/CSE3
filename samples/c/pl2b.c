#include <stdio.h>

int m, n;

int power(int m, int n) {
  if (n <= 0) {
    return 1;
  } else {
    return power(m, n - 1) * m;
  }
}

int main() {
  scanf("%d\n", &m);
  scanf("%d\n", &n);
  printf("%d\n", power(m, n));

  return 0;
}