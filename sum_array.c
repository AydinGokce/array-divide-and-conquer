#include "sum_array.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) \
    ({ \
        __typeof__(a) _a = (a); \
        __typeof__(b) _b = (b); \
        _a < _b ? _a : _b; \
    })

#define ceil_divide(a, b) \
    ({ \
        __typeof__(a) _a = (a); \
        __typeof__(b) _b = (b); \
        (_a + _b - 1) / _b; \
    })

/**
 * @brief sums the values of an array by splitting the task among a specified number of threads
 * 
 * @param int_array pointer to the integer array
 * @param array_len length of the dynamically allocated array
 * @param n_threads number of threads to split the addition task
 * @return int sum of the integers in the array
 */
int sum_array(int * int_array, int array_len, int n_threads) {
    int i;
    int sum = 0;

    int* results_array = calloc(n_threads, sizeof(int));
    pthread_t threads[n_threads];
    int indices_per_thread = ceil_divide(array_len, n_threads);

    for (i = 0; i < n_threads; i++) {
        sum_job* job = malloc(sizeof(sum_job));
        job->int_array = int_array + (i * indices_per_thread);
        job->thread_num = i;
        job->num_to_sum = min(array_len - (i * indices_per_thread), indices_per_thread);
        job->results_array = results_array;
        pthread_create(&threads[i], NULL, sum_thread, job);
    }

    for (i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for(int i = 0; i < n_threads; i++) {
        sum += results_array[i];
    }

    free(results_array);
    return sum;
}

/**
 * @brief helper function which sums up a subsection of the array
 * 
 * @param job_uncast sum_job struct which contains the instructions for the job
 */
void* sum_thread(void* job_uncast) {
    sum_job* job = (sum_job*)job_uncast;
    int subresult = 0;
    for(int i = 0; i < job->num_to_sum; i++) {
        subresult += job->int_array[i];
    }
    job->results_array[job->thread_num] = subresult;
    free(job_uncast);
}