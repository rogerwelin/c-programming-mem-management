#include <stdio.h>


int main(int argc, char* argv[]) {
  int a = 16;
  int* p = &a;
  *p = 17;

  // below would set the memory address of p to 17 - which ofc crashes the program
  // p = 17;


  // this only prints the memory address since its a pointer
  printf("%d\n", p);

  // we need dereferencing it to get actual value
  printf("%d\n", *p);

  return 0;
}
