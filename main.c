#include <stdio.h>
#include <stdlib.h>
#include "radar.h"

void input_length_details();
void input_weightage_data();
void permutation_user_loop();

int SAMPLE_LENGTH;
int PERMUTATION_LENGTH;
int *WEIGHTAGE;
int *WEIGHTAGE_VALUE_MAIN;
int *PERMUTATION_ARRAY;

void input_length_details() {
    printf("Enter number of samples: ");
    scanf("%d", &SAMPLE_LENGTH);
    printf("Enter number of  permuatation length: ");
    scanf("%d", &PERMUTATION_LENGTH);
}

void input_weightage_data() {
    int i, j;
    WEIGHTAGE = (int * ) malloc(sizeof(int) * SAMPLE_LENGTH);
    for(i = 0; i < SAMPLE_LENGTH; ++i) 
        WEIGHTAGE[i] = -1;

    for(i = 0; i < SAMPLE_LENGTH; ++i) {
        printf("Total %d samples, Enter their weightage: ", SAMPLE_LENGTH);
        for(j = 0; j < SAMPLE_LENGTH; ++j)
            if(WEIGHTAGE[j] == -1)
                printf(" x");
            else 
                printf(" %d", WEIGHTAGE[j]);
        printf("\nEnte the weightage of sample #%d: ", i+1);
        scanf("%d", &WEIGHTAGE[i]);
        _CLEAR_SCREEN_;
    }
}

void permutation_user_loop() {
    char answer;
    do {
        randomize(PERMUTATION_ARRAY, PERMUTATION_LENGTH);
        start_simulation(PERMUTATION_ARRAY, PERMUTATION_LENGTH, SAMPLE_LENGTH);
        fflush(stdin);
        printf("\nEnter 'y' for next permutaion: ");
        scanf("%c", &answer);
    }
    while (answer == 'y');
}

int main() {
    char answer;
    do {
        _CLEAR_SCREEN_;
        input_length_details();

        _CLEAR_SCREEN_;
        input_weightage_data();

        _CLEAR_SCREEN_;
    
        PERMUTATION_ARRAY = (int * )malloc(sizeof(int) * PERMUTATION_LENGTH);
        WEIGHTAGE_VALUE_MAIN = (int * )malloc(sizeof(int) * SAMPLE_LENGTH);

        if(make_permutaion_intital_array(SAMPLE_LENGTH, PERMUTATION_LENGTH, WEIGHTAGE, WEIGHTAGE_VALUE_MAIN)) {

            make_array(SAMPLE_LENGTH, PERMUTATION_LENGTH, WEIGHTAGE_VALUE_MAIN, PERMUTATION_ARRAY);
            permutation_user_loop();
        }
        else {
            printf("Frequency distribution error!\n");
            return -1; 
        }
        free(PERMUTATION_ARRAY);
        free(WEIGHTAGE_VALUE_MAIN);
        _CLEAR_SCREEN_;
        fflush(stdin);
        printf("Run Simulation with different data?\nEnter 'y' for yes: ");
        scanf("%c", &answer);
    }
    while (answer == 'y');
    return 0;
}