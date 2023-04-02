int quick(int *arr, int n) {
    int ops = 0;
    if (n < 2) {
        return 0;
    }
    int pivot = arr[0];
    ops += 3;
    int left = 0, right = n - 1;
    ops += 5;
    while (left <= right) {
        ops += 3;
        while (left < n - 1 && arr[left] < pivot) {
            ops += 7;
            left++;
            ops += 3;
        }
        while (right > 0 && arr[right] > pivot) {
            ops += 7;
            right--;
            ops += 3;
        }
        if (left <= right) {
            ops += 3;
            std::swap(arr[left], arr[right]);
            ops += 5;
            left++;
            right--;
            ops += 6;
        }
    }
    ops += quick(arr, left);
    ops += quick(&arr[left], n - left);
    return ops;
}