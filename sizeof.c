#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  signed int a = 5;
  unsigned int b = 10;
  long int c = 1000;
  float d = 10000.0;
  double e = 10000.12;

  // in c a array is a pointer to the first element
  // so one can write arr[1] or *(arr + 1) and both would be the value 2.
  int arr[3] = {50, 2, 3};
  int arr2[10] = {1, 2, 3};
  int* arrp = arr;

  printf("%llu\n", sizeof(a)); // 4b
  printf("%llu\n", sizeof(b)); // 4b
  printf("%llu\n", sizeof(c));  // 8b
  printf("%llu\n", sizeof(d));  // 4b
  printf("%llu\n", sizeof(e));  // 8b

  printf("%llu\n", sizeof(arr)); // 12b
  printf("%llu\n", sizeof(arr2)); // 40b
  printf("%llu\n", sizeof(arrp)); // 8b (pointer is 8b)
 
  return 0;
}
