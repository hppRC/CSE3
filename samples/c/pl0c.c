#include <stdio.h>

int n, x;

void prime() {
  int m;
  m = x / 2;
  while (x != (x / m) * m) {
    m = m - 1;
    if (m == 1) {
      printf("%d\n", x);
    }
  }
  return;
}

int main() {
  scanf("%d\n", &n);
  for (int i = 2; i < n; i++) {
    x = i;
    prime();
  }
  return 0;
}