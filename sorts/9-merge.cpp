int merge(int *arr, int l, int r) {
    int ops = 0;
    int currL = 0, currR = 0, curr = 0;
    ops += 6;
    int *left = new int[l];
    ops += 3;
    for (int i = 0; i < l; ++i) {
        ops += 6;
        left[i] = arr[i];
        ops += 3;
    }
    ops += 2;
    int *right = new int[r];
    ops += 3;
    for (int i = 0; i < r; ++i) {
        ops += 6;
        right[i] = arr[l + i];
        ops += 3;
    }
    ops += 2;
    while (currL < l || currR < r) {
        ops += 7;
        if (currL < l && (currR == r || left[currL] < right[currR])) {
            ops += 6;
            arr[curr] = left[currL];
            currL++;
        } else {
            arr[curr] = right[currR];
            currR++;
            ops += 6;
        }
        ops += 12;
        curr++;
        ops += 3;
    }
    return ops;
}


int mergeSort(int *arr, int n) {
    int ops = 0;
    if (n < 2) {
        return 0;
    }
    int m = n / 2;
    ops += 4;
    ops += mergeSort(arr, m);
    ops += mergeSort(&arr[m], n - m);
    ops += merge(arr, m, n - m);
    return ops;
}