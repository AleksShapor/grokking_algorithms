#include <stdio.h>

int sum_rec(int * arr, size_t len) {
    static int i = 0;
    
    if(!arr || !len)
        return 0;
    
    return arr[i] + sum_rec(&arr[i + 1], len - 1);
}

int main() {
    int arr[] = { 1, 5, 7, 8 ,10};
    printf("SUM: %d\n", sum_rec(&arr[0], sizeof(arr)/sizeof(arr[0])));
    return 0;
}
