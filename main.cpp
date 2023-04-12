#include <chrono>
#include <iostream>
#include <fstream>
#include "algorithms/1-naive.cpp"
#include "algorithms/2-kmp-standard.cpp"
#include "algorithms/3-kmp-refined.cpp"
#include "algorithms/4-z-func.cpp"
#include "texts.cpp"

/*
 * АиСД-2, 2023, задание 2
 * Васильева Алёна Дмитриевна БПИ218
 * IDE: Clion
 */

// TODO conclusions
// TODO Z-function

using namespace std;

int MEASURE_TIMES = 1; // TODO 10
std::string algorithm_name;
std::string text_name;
int pattern_size = 0;
char separator = ';';
std::ofstream results;
std::ofstream input;
std::ofstream output;

// Записывает результаты измерений в нужный файл
void record(int x) {
    results << algorithm_name << separator
            << text_name << separator
            << pattern_size << separator
            << x << "\n";
}

// Измеряет время выполнения функции
long long evaluate(vector<int> (func)(string, string), const string& text, const string& pattern) {
    input << text << ' ' << pattern << '\n';
    vector<int> ocurrs;

    auto startTime = std::chrono::high_resolution_clock::now();

    ocurrs = func(text, pattern);

    auto endTime = std::chrono::high_resolution_clock::now();

    auto timeElapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(
        endTime - startTime
    ).count();

    for (int ocurr : ocurrs) {
        output << ocurr << ' ';
    }
    output << '\n';
    return timeElapsed;
}

// Итерация по количеству измерений времени
void iterateMeasureTimes(vector<int> (func)(string, string), const string& text, const string& pattern) {
    double sum = 0;
    for (int i = 0; i < MEASURE_TIMES; ++i) {
        sum += evaluate(func, text, pattern);
    }
    double avg = sum / MEASURE_TIMES;
    record(avg);
}

// Итерация по паттернам
void iteratePatterns(vector<int> (func)(string, string), const string& text, int wildcards) {
    string pattern;
    for (int i = 100; i <= 3000; i += 100) { // TODO 100, 3000, 100
        pattern_size = i;
        pattern = text.substr(1000, i);
        for (int j = 0; j < wildcards; ++j) {
            pattern[wildcard[j] % pattern.size()] = '?';
        }
        iterateMeasureTimes(func, text, pattern);
    }
}

// Итерация по исходным текстам
void iterateTexts(vector<int> (func)(string, string)) {
    for (auto & array : getTexts()) {
        text_name = array.second;
        iteratePatterns(func, array.first.first, array.first.second);
    }
}

// Итерация по алгоритмам поиска подстрок
void iterateAlgorithms() {
    pair<vector<int> (*)(string, string), const char *> sorts[] = {
//            make_pair(naive, "naive"),
//            make_pair(kmpStandard, "kmp-standard"),
//            make_pair(kmpRefined, "kmp-refined"),
            make_pair(zFunction, "z-function"),
    };
    for (auto & sort : sorts) {
        algorithm_name = sort.second;
        iterateTexts(sort.first);
    }
}

int main() {
    input.open("../input.txt", std::ios_base::beg);
    output.open("../output.txt", std::ios_base::beg);

    results.open("../data.csv");
    iterateAlgorithms();
    results.close();
    return 0;
}
