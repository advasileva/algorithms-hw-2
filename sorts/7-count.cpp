int MAX = 4101;

// Копипаст из контеста
int counting(int *arr, int n) {
    int ops = 0;
    int *counter = new int[MAX];
    ops += 2;
    for (int i = 0; i < MAX; ++i) {
        ops += 6;
        counter[i] = 0;
        ops += 1;
    }
    int curr = 0;
    ops += 2;
    for (int i = 0; i < n; ++i) {
        ops += 6;
        counter[arr[i]]++;
        ops += 4;
    }
    ops += 2;
    for (int i = 0; i < MAX; ++i) {
        ops += 6;
        for (int j = 0; j < counter[i]; ++j) {
            ops += 6;
            arr[curr] = i;
            ops += 3;
            curr++;
            ops += 3;
        }
        ops += 2;
    }
    ops += 2;
    delete[] counter;
    return ops;
}