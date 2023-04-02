#include <algorithm>

/*
 * O(n^2)
 */
int bubbleIverson1(int *arr, int n) {
    int ops = 0;
    bool flag = true;
    ops += 2;
    for(int i = 0; flag; i++) {
        ops += 4;
        flag = false;
        ops += 2;
        for (int j = 0; j < n - i - 1; j++) {
            ops += 8;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                ops += 5;
                flag = true;
                ops += 2;
            }
            ops += 3;
        }
        ops += 2;
    }
    ops += 2;
    return ops;
}