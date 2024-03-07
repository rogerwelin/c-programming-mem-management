#include <stdlib.h>
#include <stdio.h>

void process_arr(int** arr, int n) {
  // some processing
  free(*arr);
  *arr = NULL; // but when doing this a double free does not crash. since if ptr is a null pointer,
  // free() does nothing
  // this means we can always check if ptr is NULL then we know it's been freed
}

int main(int argc, char* argv[]) {
  int* p = malloc(sizeof(int));
  *p = 1;

  // only need to free p not q, or q and not p (since both point to the same block of memory)
  // freeing both will actually crash the program so we need to watch out for double free
  int* q = p;

  // this will crash the program; double free
  process_arr(&p, 10);
  free(p);

  if (p == NULL) {
    printf("%s\n", "pointer has been freed. no need to run free on it");
  }

  return 0;
}
