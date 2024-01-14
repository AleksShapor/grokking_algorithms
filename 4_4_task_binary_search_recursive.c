#include <stdio.h>

int binary_search_recursive(int * arr, size_t len, int item) {
    
    if(!arr || !len)
        return -1;
    
    int min = 0, max = len - 1, mid = (min + max)/2, guess = arr[mid];
    
    if(guess == item) // take what we need
        return item;
    else if(guess > item) // too high
        return binary_search_recursive(&arr[0], mid, item);
    else // too low
        return binary_search_recursive(&arr[mid + 1], len - mid, item);
}

int main() {
    int arr[] = { 1, 5, 7, 8 ,10};
    printf("RESULT: %d\n", binary_search_recursive(&arr[0], sizeof(arr)/sizeof(arr[0]), 8));
    return 0;
}
