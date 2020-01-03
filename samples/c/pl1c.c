//複数引数用のテストが配布プログラムになかったので作った

#include <stdio.h>

int n, temp;

void fact(int n, int m) {
  int k;
  k = 0;
  if (n <= 1) {
    temp = 1;
  } else {
    fact(n - 1, m);
    temp = temp * n;
  }
  return;
}

int main() {
  scanf("%d\n", &n);
  fact(n, 1);
  printf("%d\n", temp);
  return 0;
}