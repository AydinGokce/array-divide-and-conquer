#include "utils.h"
#include <stdlib.h>

/**
 * @brief returns a pointer to an array of random integers of specified length
 * 
 * @param len length of the array
 * @param max_value maximum random value (from 0) for each integer
 * @return int* pointer to dynamically allocated integer array
 */
int* get_random_array(long len, int max_value) {
    int* arr = calloc(len, sizeof(int));
    for(long i = 0; i < len; i++) {
        arr[i] = rand() % max_value;
    }
    return arr;
}

/**
 * @brief sums up an integer array in a simple, foolproof manner for benchmarking
 * 
 * @param arr pointer to start of array to be summed up
 * @param len length of array
 * @return int returns the sum of the integers in the array
 */
int sum_array_benchmark(int* arr, int len) {
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum;
    free(arr);
}