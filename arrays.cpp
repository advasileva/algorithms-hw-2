#include <random>

int SIZE = 4100;

int* copy(int *arr, int n) {
    int *copy = new int[SIZE];
    for (int i = 0; i < n; ++i) {
        copy[i] = arr[i];
    }
    return copy;
}

int* smallRange() {
    int *arr = new int[SIZE];
    srand((unsigned) time(NULL));
    int min = 0, max = 5;
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = min + (rand() % static_cast<int>(max - min + 1));
    }
    return arr;
}

int* bigRange() {
    int *arr = new int[SIZE];
    srand((unsigned) time(NULL));
    int min = 0, max = 4000;
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = min + (rand() % static_cast<int>(max - min + 1));
    }
    return arr;
}

int* almostSorted() {
    int *arr = new int[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = i;
    }
    for (int i = 2; i < SIZE; i *= 2) {
        std::swap(arr[i], arr[SIZE - i]);
    }
    return arr;
}

int* reversed() {
    int *arr = new int[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = SIZE - i;
    }
    return arr;
}

int *smallRange_ = smallRange();
int *bigRange_ = bigRange();
int *almostSorted_ = almostSorted();
int *reversed_ = reversed();