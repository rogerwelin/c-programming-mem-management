#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>



// size_t is it's own data type, it's not a int
int main(int argc, char* argv[]) {

  char str[] = "this is an example";

  // the reason size_t exists is that it's large enough
  // to represent any 'object' in C, ie. things in memory like strings
  // it's an unsigned int but larger than an int
  // size_t MINIMUM range is therefore...
  // 0 to ~4 000 000 000
  // which means it can be too big to cast to an int
  // and cause integer overflow in our program why it's good practice to
  // NOT cast it to an int. since it can have negative numbers with range:
  // -2 000 0000 000 to ~2 000 000 000 (on modern systems 64bit)

  // we'll use size_t since that's also what strlen 
  // returns, so we won't do any unneccessary casting
  for(size_t i = 0; i < strlen(str); i++) {
    printf("%zu\n", i);
  }

  // malloc also returns a size_t
  int* arr = malloc(sizeof(int) * 12);
  free(arr);


  // example of int overflow;
  int _int = 2147483648;
  printf("%d\n", _int);

  // size_t does not overflow since its larger
  size_t _sizet = 2147483648;
  printf("%zu\n", _sizet);

  // SIZE_MAX lets us know how big value we can store on our system
  printf("%zu\n", SIZE_MAX);

  return 0;
}
