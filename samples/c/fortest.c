#include <stdio.h>

int i, s, n;

int main() {
  s = 0;
  scanf("%d\n", &s);
  for (i = 0; i <= n; i++) {
    s = s + i;
  }
  printf("%d\n", s);
  return 0;
}