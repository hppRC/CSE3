#include <stdio.h>

int i, n, a[100];

//添字の関係で完全に同一のLLVMコードとなるわけではないことに注意⚠️
void initialize() {
  int i;
  for (i = 0; i < 100; i++) {
    a[i] = 0;
  }
  return;
}

void check(int p) {
  int i;
  i = p;
  while (i <= 100) {
    a[i] = 1;
    i = i + p;
  }
}

int main() {
  initialize();
  scanf("%d\n", &n);
  if (n <= 100) {
    for (i = 2; i <= n; i++) {
      if (a[i] == 0) {
        printf("%d\n", i);
        check(i);
      }
    }
  }
  return 0;
}