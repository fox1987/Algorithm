#include <stdio.h>

void Swap(int &a ,int &b) {
  if (a < b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
}
/*
 * 避免除法
 */
int GCD(int a, int b){
  Swap(a, b);
  int gcd = 1;
  while (a > b && b >1) {
    if (a %2 == 0 && b %2 == 0) {
      gcd *= 2;
      a /= 2;
      b /= 2;
    } else if(a % 2 ==0 && b % 2 != 0) {
      a /= 2;
      Swap(a, b);
    } else if(a % 2 != 0 && b % 2 == 0) {
      b /= 2;
    } else  {
      a -= b;
      Swap(a, b);
    }
  }
  return gcd * b;
} 
/*
 * 辗转相除法
 */
int GCD1(int a, int b) {
  Swap(a, b);
  while (a >= b) {
    if (a % b == 0) {
      return b;
    }
    a = a % b;
    Swap(a, b);
  }
}
int main(int argc,char** argv) {
  int a , b;
  scanf("%d %d", &a, &b);
  printf("GCD(%d,%d) is %d\n", a, b, GCD(a, b));
  printf("GCD1(%d,%d) is %d\n", a, b, GCD1(a, b));
}
