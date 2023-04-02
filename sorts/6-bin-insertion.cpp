int ops6 = 0;

// Первый элемент geq x (левый поиск)
// (из контеста)
int search(int *arr, int x, int l, int r) {
    int m;
    ops6 += 1;
    while (l < r) {
        m = (l + r) / 2;
        ops6 += 4;
        if (arr[m] >= x) {
            r = m;
            ops6 += 3;
        } else {
            l = m + 1;
            ops6 += 4;
        }
        ops6 += 3;
    }
    ops6 += 3;
    return l;
}


int binInsertion(int *arr, int n) {
    ops6 = 0;
    int k;
    ops6 += 1;
    for(int i = 1; i < n; i++) {
        ops6 += 6;
        k = search(arr, arr[i], 0, i);
        for (int j = i - 1; j >= k; j--) {
            ops6 += 6;
            std::swap(arr[j], arr[j + 1]);
            ops6 += 5;
        }
        ops6 += 4;
    }
    ops6 += 2;
    return ops6;
}
