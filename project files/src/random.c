#include "../include/common.h"
#include <stdlib.h>
#include <time.h>

void randomize(int *arr, int len) {
  srand(time(NULL));
  // Fisher-Yates shuffle algorithm for randomizing the array
  for (int i = len - 1; i > 0; --i) {
    int j = rand() % (i + 1);
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}
