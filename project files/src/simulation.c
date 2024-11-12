#include "../include/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#ifndef _CLEAR_SCREEN_MAC_
#define _CLEAR_SCREEN_ system("clear")
#endif  // Platform-specific screen clearing (optional)

void input_radar_count(const int len) {
  _CLEAR_SCREEN_;
  int i, j;
  Radar *techniques = (Radar *)malloc(sizeof(Radar) * len);

  // Initialize technique count to -1 (unknown)
  for (i = 0; i < len; ++i) {
    techniques[i].id = i + 1;
    techniques[i].technique_count = -1;
  }

  // ... User interaction to get radar count for each technique (replace with your logic)

  // Free allocated memory
  free(techniques);
}

void start_simulation(const int *arr, const int len, const int sample_length) {
  printf("Starting Simulation...\n");

  // Simulate radar jamming for each technique in the permutation (replace with your logic)
  for (int i = 0; i < len; ++i) {
    int technique_id = arr[i];
    printf("Simulating Jamming for Technique %d...\n", technique_id);

    // ... Implement logic to simulate jamming for a specific technique
    // ... This could involve random delays, signal strength manipulation, etc.
    // ... Update results based on simulation outcome

    // ... (Optional) Introduce pauses or sleep between techniques for visualization

    printf("Jamming Simulation for Technique %d Complete.\n\n", technique_id);
  }

  printf("Simulation Completed.\n");
}