#include <stdio.h>
#include <stdlib.h>

// globalApa is globally allocated and deallocates when the program ends
int globalApa = 5;

void apa() {
  // apa is staticly allocated on the stack and deallocates itself when function apa() ends
  int apa = 5;
}


// following function does not work in C, it allocates a arr on the stack and returns it
// however when the function is finished the array is deallocated. the returned value is then useless
// for the caller
int* random_arr_wont_work() {
  int arr[10];

  srand(0);
  for (int i = 0; i < 10; i++) {
    arr[i] = rand() % 100;
  }

    return arr;
}

// since above won't work we need to dynamically allocate the arr
// this code works but will easily create a mem leak of caller don't free it
int* random_arr_mem_leak_maybe() {
  int* arr = malloc(sizeof(int));

  srand(0);

  for (int i = 0; i < 10; i++) {
    arr[i] = rand() % 100;
  }

    return arr;
}


void random_arr_no_leak(int* arr, int n) {
  srand(0);
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
}

int main(int argc, char *argv[]) {
  // dynamically allocated so user is required to free it 
  int *apaDyn = malloc(sizeof(int));
  *apaDyn = 5;
  free(apaDyn);


  // this will create a memory leak if we dont free it
  // and it's quite hard to know that it needs dynamically allocated in the function
  // also if we modify the arr like; arr[3] = 10; this is also a mem leak
  // since memory address will be different than in the beginning
  //int* arr = random_arr_mem_leak_maybe();


  // the most efficient solution is below
  // we don't dynamically allocate (which we could), but allocate on the stack
  // use our function and don't need to free
  int arr[10];
  random_arr_no_leak(arr, 10);
  printf("%d \n", *arr);


  return 0;
}
