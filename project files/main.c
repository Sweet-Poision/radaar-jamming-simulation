#include "include/common.h"

int main() {
  // User input for sample and permutation length, weightage data
  int sample_length, permutation_length;
  int *weightage = (int *)malloc(sizeof(int) * MAX_RADARS);  // Adjust based on needs
  int i;

  printf("Enter the sample length: ");
  scanf("%d", &sample_length);

  printf("Enter the permutation length: ");
  scanf("%d", &permutation_length);

  printf("Enter weightage for each technique (total must add up to 100):\n");
  for (i = 0; i < MAX_RADARS; ++i) {
    printf("Technique %d: ", i + 1);
    scanf("%d", &weightage[i]);
  }

  // Check if weightage adds up to 100
  int sum = 0;
  for (i = 0; i < MAX_RADARS; ++i) {
    sum += weightage[i];
  }
  if (sum != 100) {
    printf("Error: Weightage must add up to 100!\n");
    return 1; // Exit with error
  }

  // Allocate memory for permutation array
  int *permutation_array = (int *)malloc(sizeof(int) * permutation_length);

  // Call functions to create permutation and run simulation
  if (!make_permutaion_intital_array(MAX_RADARS, permutation_length, weightage, permutation_array)) {
    printf("Error: Invalid weightage for permutation.\n");
    return 1; // Exit with error
  }
  make_array(MAX_RADARS, permutation_length, weightage, permutation_array);
  start_simulation(permutation_array, permutation_length, sample_length);

  // Free allocated memory
  free(weightage);
  free(permutation_array);

  return 0;
}