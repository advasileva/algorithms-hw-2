/*
 * O(n^2)
 */
int shell(int *arr, int n) {
    int ops = 0;
    for (int i = n / 2; i > 0 ; i /= 2) {
        ops += 6;
        for (int j = i; j < n; ++j) {
            ops += 6;
            for (int k = j; k >= i && arr[k] < arr[k - i]; k -= i) {
                ops += 12;
                std::swap(arr[k], arr[k - i]);
                ops += 5;
            }
            ops += 3;
        }
        ops += 3;
    }
    ops += 4;
    return ops;
}