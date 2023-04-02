#include <algorithm>

/*
 * O(n^2)
 */
int selection(int *arr, int n) {
    int ops = 0;
    int min;
    ops += 1;
    for(int i = 0; i < n - 1; i++) {
        ops += 7;
        min = i;
        ops += 3;
        for (int j = i + 1; j < n; j++) {
            ops += 6;
            if (arr[j] < arr[min]) {
                min = j;
                ops += 3;
            }
            ops += 3;
        }
        ops += 2;
        std::swap(arr[i], arr[min]);
        ops += 5;
    }
    ops += 2;
    return ops;
}