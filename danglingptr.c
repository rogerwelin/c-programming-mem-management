#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// #define safe_free_mem(ptr) safe_free_mem((void **) &(ptr))

// since setting ptr to NULL each time when freeing memory is easily missed
// a good approach is to create a utility method
// arg is pointer to a pointer - the mem address of the pointer variable
void safe_free_mem(void **ptr) {
  // when deref a pointer to a pointer we get the pointer variable
  // that stores the mem address of block of mem we wanna free
  assert(ptr);
  free(*ptr);
  *ptr = NULL;
}

// example of defensive programming in c
// check if ptr is null or not before doing stuff
int do_work(int *ptr) {
  if (ptr == NULL) {
    return -1;
  }

  *ptr = *ptr + 1;
  return 0;
}


int main(void) {

  int* ptr = malloc(sizeof(int));
  int* ptr2 = malloc(sizeof(int));
  *ptr = 5;
  *ptr2 = 5;

  printf(" ptr before: %p\n", ptr);
  printf(" ptr before: %d\n", *ptr);

  free(ptr);

  // this is called danling pointer
  // even after we have done free, ptr keeps the memory address
  // which mean we can modify it, this can lead to security issues
  printf(" ptr after: %p\n", ptr);
  *ptr = 99;
  printf(" ptr after: %d\n", *ptr);

  // we can fix this by set ptr to point to null
  // so this pointer cannot access the memory anymore
  // we should do this after calling free()
  ptr = NULL;

  safe_free_mem((void **) &ptr2);


  return 0;
}
