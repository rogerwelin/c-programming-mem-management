#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
  int arr1[] = {1, 2};
  int arr2[] = {3, 4, 5, 6, 7, 8, 9};
  int arr3[] = {1, 2}; // arr1 and arr3 are the same
  int arr4[] = {6, 2}; // arr1 and arr4 is not the same

  // memory compare . compare mem if is same exactly the same, 2 pointers and size to compare
if (memcmp(arr1, arr4, 3 * sizeof(int)) == 0) {
    printf("arrays are the same\n");
    return 0;
  }

  printf("arrays are not the same\n");

  // copy memory from one place to another
  int arrz1[] = {3, 4};
  int arrz2[] = {1, 2};
  int arrz3[] = {1, 2};

  // copies n bytes from memory area src to memory area dst.
  memcpy(arrz2, arrz1, 2 * sizeof(int));
  printf("%d %d\n", arrz1[0], arrz1[1]);

  // memset sets the whold array/str to a value
  memset(arrz3, 0, 2 * sizeof(int));
  printf("%d %d\n", arrz3[0], arrz3[1]);

  // but it's more tricky to set the value to like 99
  memset(arrz3, 99, 2 * sizeof(int));
  printf("%d %d\n", arrz3[0], arrz3[1]);


}
