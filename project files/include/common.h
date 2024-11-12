#ifndef COMMON_H_
#define COMMON_H_

#define MAX_RADARS 10  // Adjust this based on your needs

// Function prototypes
int make_permutaion_intital_array(int len1, int len2, int *arr, int *arr2);
void make_array(const int len1, const int len2, const int *arr, int *arr2);
void randomize(int *arr, int len);
void start_simulation(const int *arr, const int len, const int technique_len);
// ... Add more prototypes as needed

// Typedefs
typedef struct {
  int id;
  int technique_count;
} Radar;

#endif /* COMMON_H_ */