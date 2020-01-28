#include <stdio.h>

int n, temp;

void fact() {
  int m;
  if (n <= 1) {
    temp = 1;
    n = n - 1;
    fact();
  } else {
    if (n >= 5) {
      temp = 1;
    } else {
      m = n;
      n = n - 1;
      fact();
      temp = temp * m;
    }
  }
  return;
}

int main() {
  scanf("%d\n", &n);
  fact();
  printf("%d\n", temp);
  return 0;
}