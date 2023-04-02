#include <math.h>

int ops8 = 0;

int digit(int x, int pos, int *pows) {
    int k = 256;
    ops8 += 7;
    return (x / pows[pos - 1]) % k;
}

// Копипаст из контеста
void radixSort(int *a, int n, int *pows) {
    int d, tmp, count, m = 11, k = 256;
    ops8 += 7;
    int *b = new int[n];
    ops8 += 3;
    for (int i = 0; i < n; ++i) {
        ops8 += 6;
        b[i] = 0;
        ops8 += 2;
    }
    ops8 += 2;
    int *c = new int[k];
    ops8 += 3;
    for (int i = 0; i < k; ++i) {
        ops8 += 6;
        c[i] = 0;
        ops8 += 2;
    }
    ops8 += 2;
    for (int i = 1; i < m; i++) {
        ops8 += 6;
        for (int j = 0; j < k; j++) {
            ops8 += 6;
            c[j] = 0;
            ops8 += 2;
        }
        ops8 += 2;
        for (int j = 0; j < n; j++) {
            ops8 += 6;
            d = digit(a[j], i, pows);
            c[d]++;
            ops8 += 3;
        }
        ops8 += 2;
        count = 0;
        ops8 += 2;
        for (int j = 0; j < k; j++) {
            ops8 += 6;
            tmp = c[j];
            c[j] = count;
            count += tmp;
            ops8 += 9;
        }
        ops8 += 2;
        for (int j = 0; j < n; j++) {
            ops8 += 6;
            d = digit(a[j], i, pows);
            b[c[d]] = a[j];
            c[d]++;
            ops8 += 11;
        }
        ops8 += 2;
        for (int j = 0; j < n; j++) {
            ops8 += 6;
            a[j] = b[j];
            ops8 += 3;
        }
        ops8 += 2;
    }
    ops8 += 2;
}

int radix(int *arr, int n) {
    ops8 = 0;
    int *pows = new int[11];
    ops8 += 3;
    for (int i = 0; i < 11; ++i) {
        ops8 += 5;
        pows[i] = 0;
        ops8 += 2;
    }
    for (int i = 0; i < 10; ++i) {
        ops8 += 5;
        pows[i] = int(pow(256, i));
        ops8 += 6;
    }
    radixSort(arr, n, pows);
    return ops8;
}