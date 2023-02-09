typedef struct sum_job {
    int* int_array;
    int num_to_sum;
    int thread_num;
    int* results_array;
} sum_job;