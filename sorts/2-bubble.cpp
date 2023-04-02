#include <algorithm>

/*
 * O(n^2)
 */
int bubble(int *arr, int n) {
    int ops = 0;
    for(int i = 0; i < n; i++) {
        ops += 6;
        for (int j = 0; j < n - i - 1; j++) {
            ops += 8;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                ops += 5;
            }
            ops += 4;
        }
        ops += 2;
    }
    ops += 2;
    return ops;
}