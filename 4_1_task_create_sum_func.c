int sum(int * arr, size_t len) {
    int res = 0;
    
    if(!arr || !len)
        return -1;
    
    for (int i = 0; i < len; i++)
        res += arr[i];
    
    return res;
}

int main() {
    int arr[] = { 1, 5, 7, 8 ,10};
    printf("SUM: %d\n", sum(&arr[0], sizeof(arr)/sizeof(arr[0])));
    return 0;
}
