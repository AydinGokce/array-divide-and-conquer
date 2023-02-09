#include "sum_array.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief generates an array of random integers, and tests sum_array against a linear O(n) benchmark
 * 
 * @param len how many integers to sum
 * @param max_num maximum value of each randomly generated integer
 * @param n_threads number of threads to spawn to sum the array
 * @return int error between the desired vs. actual sum
 */
int test_array(int len, int max_num, int n_threads) {
    int* arr = get_random_array(len, max_num);
    int sum = sum_array(arr, len, n_threads);
    int benchmark = sum_array_benchmark(arr, len);
    int p = sum - benchmark;
    printf("error (%d, %d): %d\n", sum, benchmark, p);
    return p;
}

/**
 * @brief creates a huge array of length 100,000, spawns 50 threads to divide the job
 * 
 */
void test_huge_array() {
    if(test_array(100000, 10, 50) != 0) {
        perror("failed testing huge array");
    }
}

/**
 * @brief creates an empty array, spawns 10 threads to sum it
 * 
 */
void test_empty_array() {
    if(test_array(0, 10, 10) != 0) {
        perror("failed testing empty array");
    }
}

/**
 * @brief test an array that is unevenly divided across threads. In this case, 8 indices for 3 threads.
 * 
 */
void test_misaligned_array() {
    if(test_array(8, 10, 3) != 0) {
        perror("failed testing misaligned array");
    }
}

/**
 * @brief generic test on an aligned array. 3 threads for 9 integers.
 * 
 */
void test_aligned_array() {
    if(test_array(9, 10, 3) != 0) {
        perror("failed testing aligned array");
    }
}

/**
 * @brief test for when the number of threads is greater than the (nonzero) number of integers. 
 * 
 */
void test_threads_gt_length() {
    if(test_array(5, 10, 10) != 0) {
        perror("failed testing when more threads than indices");
    }
}

/**
 * @brief testing against an obviously verifiable sum, for sanity.
 * 
 */
void test_known_quantity() {
    int known_arr[10] = {1,2,3,4,5,6,7,8,9,0};
    if(sum_array(known_arr, 10, 6) != 45) {
        perror("failed testing against known quantity");
    }
}