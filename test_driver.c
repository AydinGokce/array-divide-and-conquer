#include "tests.h"
#include "sum_array.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

void exit_with_instructions(void);

/**
 * @brief tests the code. run with --demo to see how the multithreading speeds up the array summation!
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {

    if((argc == 2 || argc == 3) && !strcmp(argv[1], "--demo")) {
        
        long demo_array_length = 1e9;
        int n_solver_threads = argc == 3 ? atoi(argv[2]) : 5;

        printf("generating array of length %ld...\n", demo_array_length);
        int *arr = get_random_array(demo_array_length, 3);

        struct timeval timecheck;

        // single threaded   
        gettimeofday(&timecheck, NULL);
        int start_single = (int)timecheck.tv_sec * 1000 + (int)timecheck.tv_usec / 1000;
        int sum_single = sum_array_benchmark(arr, demo_array_length);
        gettimeofday(&timecheck, NULL);
        int dt_single = ((int)timecheck.tv_sec * 1000 + (int)timecheck.tv_usec / 1000) - start_single;


        // multi threaded
        gettimeofday(&timecheck, NULL);
        int start_multi = (int)timecheck.tv_sec * 1000 + (int)timecheck.tv_usec / 1000;
        int sum_multi = sum_array(arr, demo_array_length, n_solver_threads);
        gettimeofday(&timecheck, NULL);
        int dt_multi = ((int)timecheck.tv_sec * 1000 + (int)timecheck.tv_usec / 1000) - start_multi;

        free(arr);

        printf("TYPE\tSUM\tTIME (ms)\n");
        printf("single\t%d    \t%d\n", sum_single, dt_single);
        printf("multi \t%d    \t%d\n", sum_multi, dt_multi);
        printf("multithreading sped up summation by %dms! (%fx)\n", dt_single - dt_multi, dt_multi == 0 ? -1 : (double)dt_single / (double)dt_multi);
        printf("----------\n");

    }
    else if(argc != 1) {
        exit_with_instructions();
    }
    
    printf("Testing summation accuracy and edge cases\n");
    test_huge_array();
    test_empty_array();
    test_misaligned_array();
    test_aligned_array();
    test_threads_gt_length();
    printf("All tests passed\n");
    
}

void exit_with_instructions() {
    printf("usage: test_driver [--demo] [num_cores]\n");
    exit(0);
}