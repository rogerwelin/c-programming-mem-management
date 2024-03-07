#include <stdio.h>


typedef struct {
  int test;     // 4b
  char k;       // 1b
  char str[10]; // 10b
  int *p;       // 8b
  short sh;     // 2b
} Thing; // Thing should be 25b if we add all together

int main(int argc, char *argv[]) {
  int i;
  Thing t = { 12, 'k', "testing", &i, 256 };

  printf("%llu\n", sizeof(t)); // we get 32b... what happened?

  return 0;
}
