#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int* arr = malloc(sizeof(int) * 256);
  // actually check that we're able to allocate the memory
  if (arr == NULL) {
    return 1;
  }

 memset(arr, 0, sizeof(int) * 256);
  
  int i;
  // when pringing the newly allocated memory it's not
  // 100% we only get 0 value. we could get leftover memory
  // reason is its inefficient for OS to clear that out
  // every time a new alloicated memory is used. this is why memset is useful
  for (int i = 0; i < 256; i++) {
    printf("%d ", arr[i]);
  }


  return 0;
}
