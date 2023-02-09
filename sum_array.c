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

int sum_array(int * int_array, int array_len, int n_threads) {
    int i;
    int sum = 0;

    int* results_array = calloc(n_threads, sizeof(int));
    int indices_per_thread = ceil_divide(array_len, n_threads);

    for (i = 0; i < n_threads; i++) {
        sum_job* job = malloc(sizeof(sum_job));
        job->int_array = int_array;
        job->thread_num = i;
        job->num_to_sum = min(array_len - i * indices_per_thread, indices_per_thread);

    }

    for (i = 0; i < n_threads; i++) {

    }



    return sum;
}

int sum_thread(sum_job* job) {
    for(int i = 0; i < job->num_to_sum; i++) {
        job->results_array[job->thread_num] += job->int_array[i];
    }
}