#include <stdio.h>
#include <string.h>

void print_arr(int * arr, size_t len) {
    printf("\n");
    for(int it = 0; it < len; it++) {
        printf(" %d ", arr[it]);
    }
    printf("\n");
}

int find_highest(int * arr, size_t len)
{
    int index = 0;
    int highest = arr[0];
    for(int it = 0; it < len; it++) {
        if(arr[it] > highest) {
            highest = arr[it];
            index = it;
        }
    }
    
    return index;
}

void sort_arr(int * arr, size_t len)
{
    int index = 0;
    int tmp_arr[len];
    // Init array
    memset(tmp_arr, 0, len*sizeof(int));
    
    // Sort array
    for(int it = 0; it < len; it++) {
        index = find_highest(arr, len);
        tmp_arr[it] = arr[index];
        arr[index] = 0;
    }
    
    // Copy sorted array to unsorted
    memcpy(arr, &tmp_arr[0], len * sizeof(int));
}

int main()
{
    int numbers[] = { 11, 213, 20, 1, 5};
    size_t len = sizeof(numbers)/sizeof(numbers[0]);
    print_arr(&numbers[0], len); // Print unsorted
    sort_arr(&numbers[0], len);
    print_arr(&numbers[0], len); // Print sorted
    return 0;
}

