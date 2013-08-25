#include <stdio.h>
#include <math.h>

int Prime(int n) {
  if (n < 2) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  for (int i = 3; i <= sqrt(n); i+=2) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char** argv) {
  int n;
  scanf("%d", &n);
  printf("%d is prime : %d\n", n, Prime(n));
  return 0;
}
