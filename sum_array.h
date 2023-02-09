/**
 * @brief pass this struct to each thread in the array summation function.
 * 
 */
typedef struct sum_job {
    int* int_array;     // pointer to start of subsection of array to sum
    int num_to_sum;     // how many indices to sum from the offset
    int* result_location; // pointer to the array for storing results of individual threads
} sum_job;

int sum_array(int * int_array, int array_len, int n_threads);
void* sum_thread(void* job_uncast);