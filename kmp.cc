#include <string.h>
#include <stdio.h>

#define MAXLEN 100
int Next[MAXLEN] = {0};

void Show(int * array, int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
void ComputeNext(const char* P) {
  size_t m = strlen(P + 1);
  Next[1] = 0;
  int k = 0;
  for (int q = 2; q <=m; ++q) {
    while (k > 0 && P[k+1] != P[q]) {
      k = Next[k];
    }
    if (P[k+1] == P[q]) {
      ++k;
    }
    Next[q] = k;
  }
  Show(Next+1, m);
}
void KMP(const char* T, const char* P) {
  size_t n = strlen(T + 1);
  size_t m = strlen(P + 1);
  ComputeNext(P);
  int q = 0;
  for (int i = 1; i <= n; ++i) {
    while (q > 0 && P[q + 1] != T[i]) {
      q = Next[q];
    }
    if (P[q + 1] == T[i]) {
      ++q;
    }
    if (q == m) {
      printf("Match in pos %lu \n", i - m);
      q = Next[q];
    }
  }
}
int main(int argc,char** argv) {
  char T[MAXLEN] = {0};
  char P[MAXLEN] = {0};

  scanf("%s %s", T+1, P+1);
  printf("%s %s\n", T+1, P+1);
  printf("strlen(%s) :%lu, strlen(%s) : %lu\n",
        T+1, strlen(T+1), P+1, strlen(P+1));
  KMP(T, P);
  return 0;
}
