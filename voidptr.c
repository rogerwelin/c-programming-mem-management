#include <stdio.h>

// void pointers are like generic pointers, they can take any type
// example is malloc that retur a void ptr
// void ptr cannot be dereferenced


// this is a func that mem bytes. it's generic in nature
// so makes sense to just use a void ptr as argument
void printBytes(void* arr, int n) {
  int i;
  for (i = 0; i < n; i ++) {
    printf("%02x ", ((char*)arr)[i]);
  }
}


int main(int argc, char* argv[]) {
  int arr[] = { 10, 20, 30, 40 };
  long arr2[] = { 12, 22, 33, 44 };
  printBytes(arr, 32);

  return 0;
}
