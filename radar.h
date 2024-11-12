#ifndef _RADAR_H_
#define _RADAR_H_

/*
    It takes three inputs len1 (total number of samples), len2 (size of array required)
    and the address of array that has all data of samples.

    It checks if the data is possible and makes a array with distribution of elements
    according to the weightage of different samples
*/
int make_permutaion_intital_array(int len1, int len2, int * arr, int * arr2);

/*
    It takes frequency value and make a distribution of numbers according to the 
    weightage of different samples
*/
void make_array(const int len1, const int len2, const int * arr, int *arr2);

/*
    It takes an array with inputs array base address and length of array and 
    randomise it using different algorithms and then start the radar simulation
*/
void randomize(int * arr, int len);

/*
    It takes an array and its length as its parameters and start the simulation
*/
void start_simulation(const int * arr, const int len, const int technique_len);

#endif


#ifndef _CLEAR_SCREEN_MAC_
#define _CLEAR_SCREEN_MAC_

/*
    System call on unix based operating systems for clearing the shell
*/
#define _CLEAR_SCREEN_ system("clear")

#endif