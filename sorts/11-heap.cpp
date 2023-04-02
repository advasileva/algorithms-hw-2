#include <algorithm>

int heapify(int *arr, int i, int n) {
    int ops = 0;
    if (i >= n) {
        return 0;
    }
    int left = 2 * i + 1, right = left + 1, largest = i;
    ops += 7;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
        ops += 3;
    }
    ops += 7;
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        ops += 3;
    }
    ops += 7;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        ops += 5;
        ops += heapify(arr, largest, n);
    }
    ops += 7;
    return ops;
}

int heap(int *arr, int n) {
    int ops = 0;
    for (int i = n / 2; i >= 0; --i) {
        ops += 6;
        ops += heapify(arr, i, n);
    }
    ops += 3;
    for (int i = n - 1; i >= 0; --i) {
        ops += 6;
        std::swap(arr[0], arr[i]);
        ops += 5;
        ops += heapify(arr, 0, i);
    }
    ops += 2;
    return ops;
}