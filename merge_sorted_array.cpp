#include <iostream>

// Merge two sorted array inplace
// But size of array A is big enough
// sizeof(A) = elements in A + elements in B
//
// Example:
//   A = [1 5 10 x x x]
//   B = [2 3 11]
//
// Result:
//   A = [1 2 3 5 10 11] 

void merge(int *a, int *b, size_t len_a, size_t len_b);

int main() {
   
  int A [] = {1, 2, 3, 0, 0 ,0};
  int B [] = {1, 2, 3}; 

  merge(&A[0], &B[0], 6, 3);

  for (int i = 0; i < 6; i++) {
    std::cout << A[i] << " ";
  }

  std::cout << "\n";

  return 0;
}

/* Merge two sorted arrays */
void merge(int *a, int *b, size_t len_a, size_t len_b) {
  
  if (!a || !b)
    return;

  int i1 = len_b - 1;
  int i2 = i1;
  int index = len_a - 1;

  while (i1 >= 0 && i2 >= 0) {
    if (a[i1] >= b[i2]) {
      a[index] = a[i1];
      i1--;
    } else {
      a[index] = b[i2];
      i2--;
    }
    index--;
  }

  while (i2 >= 0) {
    a[index] = b[i2];
    i2--;
    index--;
  }
}
