int a[10];
int i, s;

int main() {
  i = 0;
  while (i < 10) {
    a[i] = i;
    i = i + 1;
  }
  i = 0;
  while (i < 10) {
    s = a[i] + s;
    i = i + 1;
  }
  return 0;
}