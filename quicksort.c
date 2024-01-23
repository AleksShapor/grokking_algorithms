#include <stdio.h>

void print_arr(int *arr, size_t len) {
    for (int it = 0; it < len; it++) {
        printf(" %d ", arr[it]);
    }
    printf("\n");
}

void quicksort(int *arr, int start, int end) {
    // Base case: if the subarray has 1 or 0 elements, it's already sorted
    if (end <= start)
        return;

    // Choose the pivot element and initialize variables
    int pivot_pos = start;  // Initial position of the pivot
    int pivot = arr[start];  // Value of the pivot
    int temp = 0;  // Temporary variable for swapping
    int j = end;  // Index for the right end of the subarray

    // Loop until the indices i and j meet
    while (1) {
        // Find the first element on the left that is greater than the pivot
        while (arr[pivot_pos] <= pivot && pivot_pos < end)
            pivot_pos++;

        // Find the first element on the right that is smaller than or equal to the pivot
        while (arr[j] > pivot)
            j--;

        // If the indices haven't crossed, swap the elements at pivot_pos and j
        if (pivot_pos < j) {
            temp = arr[pivot_pos];
            arr[pivot_pos] = arr[j];
            arr[j] = temp;
        } else {
            // If the indices have crossed, break out of the loop
            break;
        }
    }

    // Swap the pivot element with the element at index j
    arr[start] = arr[j];
    arr[j] = pivot;

    // Recursively sort the subarrays on the left and right of the pivot
    quicksort(arr, start, j - 1);
    quicksort(arr, j + 1, end);
}


int main() {
    int arr_input[] = {20, 1, 14, 4, 3, 9, 10, 2};
    printf("Input:       ");
    print_arr(&arr_input[0], sizeof(arr_input) / sizeof(arr_input[0]));

    quicksort(arr_input, 0, sizeof(arr_input) / sizeof(arr_input[0]) - 1);
    printf("Your answer: ");
    print_arr(&arr_input[0], sizeof(arr_input) / sizeof(arr_input[0]));

    return 0;
}
