int insertion(int *arr, int n) {
    int ops = 0;
    int curr;
    ops += 1;
    for(int i = 1; i < n; i++) {
        ops += 6;
        curr = arr[i];
        ops += 3;
        for (int j = i - 1; j >= 0 && arr[j] > curr; j--) {
            ops += 9;
            arr[j + 1] = arr[j];
            ops += 3;
        }
        ops += 2;
        arr[i + 1] = curr;
        ops += 4;
    }
    ops += 2;
    return ops;
}