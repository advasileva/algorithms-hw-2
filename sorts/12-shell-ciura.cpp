/*
 * -> O(nlog(n))
 */
int shellCiura(int *arr, int n) {
    int ops = 0;
    int ciura[] = {1 , 4, 10, 23, 57, 132, 301, 701, 1750};
    ops += 9;
    for (int i : ciura) {
        ops += 2;
        for (int j = i; j < n; ++j) {
            ops += 6;
            for (int k = j; k >= i && arr[k] < arr[k - i]; k -= i) {
                ops += 10;
                std::swap(arr[k], arr[k - i]);
                ops += 5;
            }
            ops += 3;
        }
        ops += 3;
    }
    return ops;
}