#include <stdio.h>

int n, temp;

void fact() {
  int m;
  if (n <= 1) {
    temp = 1;
  } else {
    while (n > 0) {
      if (n >= 10) {
        temp = n;
        n = n - 1;
        printf("%d\n", temp);
      } else {
        m = n;
        n = n - 1;
        temp = temp * m;
      }
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