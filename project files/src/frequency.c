#include "../include/common.h"
#include <stdlib.h>

int make_permutaion_intital_array(int len1, int len2, int *arr, int *arr2) {
  // Check if the total weightage adds up to the desired permutation length
  int sum = 0;
  for (int i = 0; i < len1; ++i) {
    sum += (int)((double)(arr[i] * len2) / 100);
  }
  if (sum != len2) {
    return 0; // Error: Frequency distribution not possible
  }

  // Create a distribution array based on weightage
  for (int i = 0; i < len1; ++i) {
    arr2[i] = (int)((double)(arr[i] * len2) / 100);
  }

  return 1; // Success
}

void make_array(const int len1, const int len2, const int *arr, int *arr2) {
  int i, j, k;

  // Allocate memory for temporary permutation array
  int *permutation = (int *)malloc(sizeof(int) * len2);

  // Initialize permutation with zeroes
  for (i = 0; i < len2; ++i) {
    permutation[i] = 0;
  }

  // Create permutation based on weightage distribution
  for (i = 0, j = 0; i < len2; ++j) {
    if (j == len1) {
      j = 0;
    }
    if (arr2[j]) {
      arr2[j]--;
      permutation[i] = j + 1;
      i++;
    }
  }

  // Copy permutation to output array
  for (i = 0; i < len2; ++i) {
    arr2[i] = permutation[i];
  }

  // Free temporary memory
  free(permutation);
}