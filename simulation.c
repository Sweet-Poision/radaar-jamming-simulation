#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#ifndef _CLEAR_SCREEN_MAC_
#define _CLEAR_SCREEN_ system("clear")
#endif

// const int WAIT_TIME = 500;
#define _PUSLE_WIDTH_ usleep(925);

void input_radar_count(const int len);
void copy_radar_data(const int * arr,const int len);
void simulate(const int len);
void * jam_radar(void * technique_id);
void printOutput(const int len);

int *RADARS;
int *TECHNIQUES;
int JAMMED_COUNT;
int *OUTPUT_ARRAY;

void * jam_radar(void * technique_id) {
    int *current_radar_jamming_technique;
    current_radar_jamming_technique = (int *)(technique_id);
    TECHNIQUES[(*current_radar_jamming_technique) - 1]--;
    _PUSLE_WIDTH_;
    TECHNIQUES[(*current_radar_jamming_technique) - 1]++;
    return NULL;
}

void simulate(const int len) {
    int i;
    pthread_t *threads;
    threads = (pthread_t * )malloc(sizeof(pthread_t) * len);
    OUTPUT_ARRAY = (int * )malloc(sizeof(int) * len * 3);
    for(i = 0; i < len; ++i) {
        OUTPUT_ARRAY[i * 3] = RADARS[i];
        OUTPUT_ARRAY[(i * 3) + 1] = TECHNIQUES[RADARS[i] - 1]; 
        if(TECHNIQUES[RADARS[i]-1] > 0) {
            pthread_create(&threads[i], NULL, jam_radar, (void *)&RADARS[i]);
            JAMMED_COUNT++;
            OUTPUT_ARRAY[(i * 3) + 2] = 1;
        }
        else {
            OUTPUT_ARRAY[(i * 3) + 2] = 0;
        }
    }
    for(i = 0; i < len; ++i) 
        pthread_join(threads[i], NULL);
}

void input_radar_count(const int len) {
    _CLEAR_SCREEN_;
    int i, j;
    TECHNIQUES = (int * ) malloc(sizeof(int) * len);
    for(i = 0; i < len; ++i) 
        TECHNIQUES[i] = -1;

    for(i = 0; i < len; ++i) {
        printf("Total %d types of radars, Enter their jamming techniques count: ", len);
        for(j = 0; j < len; ++j)
            if(TECHNIQUES[j] == -1)
                printf(" x");
            else 
                printf(" %d", TECHNIQUES[j]);
        printf("\nEnter the count of jaming technique #%d: ", i+1);
        scanf("%d", &TECHNIQUES[i]);
        _CLEAR_SCREEN_;
    }
}

void copy_radar_data(const int * arr,const int len) {
    int i;
    RADARS = (int * )malloc(sizeof(int) * len);
    for(i = 0; i < len; ++i) 
        RADARS[i] = arr[i];
}

void printOutput(const int len) {
    int i, j;
    char result;
    _CLEAR_SCREEN_;
    printf("RADAR LOG\n\n%10s %10s %10s %10s\n", "S.No.", "ID", "RESULT", "REM");
    for( i = 0; i < len; ++i) {
        j = i * 3;
        if(OUTPUT_ARRAY[j + 2])
            result = 'S';
        else
            result = 'F';
        printf("%10d %10d %10c %10d\n", i+1, OUTPUT_ARRAY[j], result, OUTPUT_ARRAY[j+1]);
    }
}

void start_simulation(const int * arr, const int len, const int technique_len) {
    input_radar_count(technique_len);
    copy_radar_data(arr,len);
    JAMMED_COUNT = 0;
    simulate(len);
    printOutput(len);
}