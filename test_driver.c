#include "tests.h"
#include "sum_array.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

    if(argc == 2 && !strcmp(argv[1], "--demo")) {
        long demo_array_length = 1e9;
        int n_solver_threads = 10;

        printf("generating array of length %ld...\n", demo_array_length);
        int *arr = get_random_array(demo_array_length, 100);


        int start_single = clock()*1000 / CLOCKS_PER_SEC;
        int sum_single = sum_array_benchmark(arr, demo_array_length);
        int dt_single = (clock()*1000 / CLOCKS_PER_SEC) - start_single;

        int start_multi = clock()*1000 / CLOCKS_PER_SEC;
        int sum_multi = sum_array(arr, demo_array_length, n_solver_threads);
        int dt_multi = (clock()*1000 / CLOCKS_PER_SEC) - start_multi;

        

        free(arr);

        printf("TYPE\tSUM\tTIME (s)\n");
        printf("single\t%d\t%d\n", sum_single, dt_single);
        printf("multi \t%d\t%d\n", sum_multi, dt_multi);
        printf("----------\n");
        //printf("multithreading sped up summation by %ds, (%dx speedup!)", dt_single - dt_multi, dt_single / dt_multi);

    }
    else if(argc != 1) {
        exit_with_instructions();
    }
    

    test_huge_array();
    test_empty_array();
    test_misaligned_array();
    test_aligned_array();
    test_threads_gt_length();
    printf("All tests complete\n");
    
}

void exit_with_instructions() {
    printf("usage: test_driver [--demo]");
    exit(0);
}