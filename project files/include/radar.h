#ifndef RADAR_H_
#define RADAR_H_

#include "include/common.h"

// Function prototypes (replace with your actual functions)
void simulate_jamming(int technique_id, int sample_length);
int analyze_results(const int *results, int len);
void print_simulation_report(const Radar *techniques, int len, const int *results);
// ... Add more function prototypes as needed

#endif /* RADAR_H_ */