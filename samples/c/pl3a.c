#include <stdio.h>

int i, j, n, a[100];

//添字の関係で完全に同一のLLVMコードとなるわけではないことに注意⚠️
void initialize(int n) {
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d\n", &a[i]);
  }
  return;
}

void swap(int j) {
  int temp;
  temp = a[j];
  a[j] = a[j + 1];
  a[j + 1] = temp;

  return;
}

int main() {
  scanf("%d\n", n);
  if (n <= 100) {
    initialize(n);
    i = n;
    while (1 <= i) {
      j = 1;
      while (j < i) {
        if (a[j] > a[j + 1]) {
          swap(j);
        }
        j = j + 1;
      }
      printf("%d\n", a[i]);
      i = i - 1;
    }
  }
  return 0;
}