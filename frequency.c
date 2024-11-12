#include <stdlib.h>

int check_possibility_of_array(const int len1, const int len2, const int * arr, int * arr2);

int *PERMUTATION;
int *WEIGHTAGE_VALUE;

void make_array(const int len1, const int len2, const int * weight_value, int * arr2) {
    int i, j, k;
    PERMUTATION = (int * )malloc(sizeof(int)*len2);  
    WEIGHTAGE_VALUE = (int * )malloc(sizeof(int) * len1);  
    for(i = 0; i < len1; ++i) 
        WEIGHTAGE_VALUE[i] = weight_value[i];


    for(i = 0, j = 0; i < len2; ++j) {
        if(j==len1)
            j = 0;
        if(WEIGHTAGE_VALUE[j]) {
            PERMUTATION[i] = j + 1;
            WEIGHTAGE_VALUE[j]--;
            i++;
        }
    }
    
    for( i = 0; i < len2; ++i) 
        arr2[i] = PERMUTATION[i];

    free(PERMUTATION);
    free(WEIGHTAGE_VALUE);
}

int check_possibility_of_array(const int len1, const int len2, const int * arr, int * arr2) {
    int sum = 0, i;
    WEIGHTAGE_VALUE = (int * )malloc(sizeof(int) * len1);
    for(i = 0; i < len1; ++i) {
        WEIGHTAGE_VALUE[i] = (double)(arr[i] * len2) / 100;
        sum = sum + WEIGHTAGE_VALUE[i];
    }

    if(sum != len2) 
        return 0;
    for(i = 0; i < len1; ++i)
        arr2[i] = WEIGHTAGE_VALUE[i];
    free(WEIGHTAGE_VALUE);
    return 1;
}

int make_permutaion_intital_array(const int len1, const int len2, const int * arr, int * arr2) {
    if(check_possibility_of_array(len1, len2, arr, arr2)) 
        return 1;
    else 
        return 0; 
}