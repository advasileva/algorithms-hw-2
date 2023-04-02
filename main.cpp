#include <chrono>
#include <iostream>
#include <fstream>
#include "sorts/0-default.cpp"
#include "sorts/1-selection.cpp"
#include "sorts/2-bubble.cpp"
#include "sorts/3-bubble-iverson-1.cpp"
#include "sorts/4-bubble-iverson-2.cpp"
#include "sorts/5-insertion.cpp"
#include "sorts/6-bin-insertion.cpp"
#include "sorts/7-count.cpp"
#include "sorts/8-radix.cpp"
#include "sorts/9-merge.cpp"
#include "sorts/10-quick.cpp"
#include "sorts/11-heap.cpp"
#include "sorts/12-shell-ciura.cpp"
#include "sorts/13-shell.cpp"
#include "arrays.cpp"

/*
 * АиСД-2, 2023, задание 1
 * Васильева Алёна Дмитриевна БПИ218
 * IDE: Clion
 * Сделано:
 *  - 13 сортировок
 *  - 4 вида массивов
 *  - Измерение времени в наносекундах
 *  - Подсчёт операций
 *  - Функция проверки отсортированности массива
 *  - Вывод входных/выходных данных в файл
 *  - Рандомная генерация чисел с srand
 *  - Массив копируется для каждой сортировки
 *  - Графики с легендами
 *  - Выводы (не сильно подробные)
 * Не сделано:
 *  - Комментов к алгоритмам сортировок нет
 *  - Операции считаются очень условно
 *  - Не стала называть все файлы <группа>_<FIO>*.*
 *  - Под санитайзерами не запускала, поэтому могут быть утечки памяти
 *  - Код и логика измерений могли быть лучше
 */

using namespace std;

int MEASURE_TIMES = 10;
std::string sort_name = "";
std::string array_name = "";
int array_size = 0;
char separator = ';';
std::ofstream results;
std::ofstream input;
std::ofstream output;
bool isSmallRange = true;
bool isTimeMeasurement = true;

// Записывает результаты измерений в нужный файл
void record(int x) {
    results << sort_name << separator
        << array_name << separator
        << array_size << separator
        << x << "\n";
}

// Выводит массив в поток вывода (файл input.txt или output.txt)
void print(int* arr, int n, std::ofstream *stream) {
    for (int i = 0; i < n; ++i) {
        *stream << arr[i] << ' ';
    }
    *stream << "\n";
}

// Проверяет, что массив отсортирован
bool check(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            for (int i = 0; i < n; ++i) {
                std::cerr << arr[i] << ' ';
            }
            std::cerr << '\n';
            throw std::invalid_argument("sort " + sort_name + " incorrect");
            return false; // да, это гениально, но я хочу ff, а по тз надо возвращать значение
        }
    }
    return true;
}

// Измеряет время выполнения функции или количество операций в зависимости от тоггла isTimeMeasurement
long long evaluate(int (*func)(int *, int), int* arr, int n) {
    print(arr, n, &input);
    int ops = 0;
    auto startTime = std::chrono::high_resolution_clock::now();

    ops = func(arr, n);

    auto endTime = std::chrono::high_resolution_clock::now();

    auto timeElapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(
        endTime - startTime
    ).count();
    print(arr, n, &output);
    check(arr, n);
    delete[] arr;
    if (isTimeMeasurement) {
        return timeElapsed;
    }
    return ops;
}

// Итерация по количеству измерений времени
void iterateMeasureTimes(int (*func)(int *, int), int* arr, int n) {
    double sum = 0;
    for (int i = 0; i < MEASURE_TIMES; ++i) {
        sum += evaluate(func, copy(arr, n), n);
    }
    double avg = sum / MEASURE_TIMES;
    record(avg);
}

// Итерация по размерам массива в зависимости от тоггла isSmallRange
void iterateSizes(int (*func)(int *, int), int* arr) {
    if (isSmallRange) {
        for (int i = 50; i <= 300; i += 50) {
            array_size = i;
            iterateMeasureTimes(func, arr, i);
        }
    } else {
        for (int i = 100; i <= 4100; i += 100) {
            array_size = i;
            iterateMeasureTimes(func, arr, i);
        }
    }
}

// Итерация по типам массивов
void iterateArraysTypes(int (*func)(int *, int)) {
    pair<int*, const char *> arrays[] = {
            make_pair(smallRange_, "small-range"),
            make_pair(bigRange_, "big-range"),
            make_pair(almostSorted_, "almost-sorted"),
            make_pair(reversed_, "reversed"),
    };
    for (auto & array : arrays) {
        array_name = array.second;
        iterateSizes(func, array.first);
    }
}

// Итерация по сортировкам
void iterateSorts() {
    pair<int (*)(int *, int), const char *> sorts[] = {
            make_pair(selection, "selection"),
            make_pair(bubble, "bubble"),
            make_pair(bubbleIverson1, "bubble-iverson-1"),
            make_pair(bubbleIverson2, "bubble-iverson-2"),
            make_pair(insertion, "insertion"),
            make_pair(binInsertion, "bin-insertion"),
            make_pair(counting, "counting"),
            make_pair(radix, "radix"),
            make_pair(mergeSort, "merge"),
            make_pair(quick, "quick"),
            make_pair(heap, "heap"),
            make_pair(shellCiura, "shell-ciura"),
            make_pair(shell, "shell"),
    };
    for (auto & sort : sorts) {
        sort_name = sort.second;
        iterateArraysTypes(sort.first);
    }
}

// Исполнение выбраного кейса
void executeCase(std::string filename) {
    results.open(filename);
    iterateSorts();
    results.close();
}

int main() {
    input.open("../input.txt", std::ios_base::beg);
    output.open("../output.txt", std::ios_base::beg);

    isTimeMeasurement = true;
    isSmallRange = true;
    executeCase("../data/time-small.csv");
    isSmallRange = false;
    executeCase("../data/time-large.csv");

    isTimeMeasurement = false;
    isSmallRange = true;
    executeCase("../data/ops-small.csv");
    isSmallRange = false;
    executeCase("../data/ops-large.csv");
    return 0;
}
