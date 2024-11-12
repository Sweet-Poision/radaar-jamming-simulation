#include <stdlib.h>
#include <time.h>

void position_random(const int * arr, const int len);
void fisher_yates(const int len);
void shuffle(const int len);
void swap(int * a, int * b);

int *ARRAY;

void swap(int * a, int * b) {
    int temp;
    temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

void shuffle(const int len) {
    int i, random_i, random_j, random_size;
    random_size = rand() % len;
    for(i = 0; i < random_size; ++i) {
        random_i = rand() % len;
        random_j = rand() % len;
        swap(&ARRAY[random_i], &ARRAY[random_j]);
    }
}

void position_random(const int * arr, const int len) {
    int i, random_i;
    for(i = 0; i < len; ++i) 
        ARRAY[i] = -1;

    for(i = 0; i < len; ++i) {
        random_i = rand() % (len);
        while(ARRAY[random_i] != -1) 
            random_i = rand() % len;
        ARRAY[random_i] = arr[i];
    }
}

void fisher_yates(const int len) {
    int i, j;
    for (i = len - 1; i > 0; --i) {
        j = rand() % (i + 1);
        swap(&ARRAY[i], &ARRAY[j]);
    }
}

void randomize(int * arr, const int len) {
    int i;
    srand (time(NULL));
    ARRAY = (int * )malloc(sizeof(int)*len);
    position_random(arr, len);
    fisher_yates(len); 
    shuffle(len);
    for(i = 0; i < len; ++i) 
        arr[i] = ARRAY[i];
    free(ARRAY);
}