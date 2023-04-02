#include <algorithm>

/*
 * O(n^2)
 */
int bubbleIverson2(int *arr, int n) {
    int ops = 0;
    int lastSwap = n, prevSwap;
    ops += 5;
    bool flag = true;
    ops += 2;
    for(int i = 0; flag; i++) {
        ops += 5;
        flag = false;
        ops += 2;
        for (int j = 0; j < lastSwap; j++) {
            ops += 6;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                ops += 5;
                flag = true;
                ops += 2;
                prevSwap = j;
                ops += 3;
            }
            ops += 3;
        }
        ops += 2;
        lastSwap = prevSwap;
        ops += 3;
    }
    ops += 2;
    return ops;
}