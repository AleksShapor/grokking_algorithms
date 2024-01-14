#include <stdio.h>

int binary_search(int * arr, size_t len, int item) {
    int guess = 0, mid = 0, min = 0, max = len - 1;
    while(min <= max) {
        mid = (min + max) / 2;
        guess = arr[mid];
        if(guess == item) // take what we need
            return mid;
        else if(guess > item) // too high
            max = mid - 1;
        else // too low
            min = mid + 1;
    }
    return -1;
}

int main() {
    int arr[5] = { 1, 5, 7, 8 ,10}, item = 10, result = 0;
    result = binary_search(&arr[0], 5, item);
    printf("RESULT IS: %d", result);
    return 0;
}
