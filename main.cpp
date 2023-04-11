#include <chrono>
#include <iostream>
#include <fstream>
#include "algorithms/1-naive.cpp"
#include "algorithms/2-kmp-standard.cpp"
#include "algorithms/3-kmp-refined.cpp"
#include "strings.cpp"

/*
 * АиСД-2, 2023, задание 2
 * Васильева Алёна Дмитриевна БПИ218
 * IDE: Clion
 */

using namespace std;

int MEASURE_TIMES = 1;
std::string algorithm_name = "";
std::string text_name = "";
char separator = ';';
std::ofstream results;
std::ofstream input;
std::ofstream output;

// Записывает результаты измерений в нужный файл
void record(int x) {
    results << algorithm_name << separator
            << text_name << separator
            << x << "\n";
}

// Измеряет время выполнения функции
long long evaluate(vector<int> (func)(string, string), string text, string pattern) {
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
void iterateMeasureTimes(vector<int> (func)(string, string), string text, string pattern) {
    double sum = 0;
    for (int i = 0; i < MEASURE_TIMES; ++i) {
        sum += evaluate(func, text, pattern);
    }
    double avg = sum / MEASURE_TIMES;
    record(avg);
}

// Итерация по паттернам
void iteratePatterns(vector<int> (func)(string, string), string text) {
    for (int i = 10; i <= 300; i += 10) { // fix to 100, 3000, 100
        iterateMeasureTimes(func, text, text.substr(1000, i));
    }
}

// Итерация по исходным текстам
void iterateTexts(vector<int> (func)(string, string)) {
    pair<string, const char *> arrays[] = {
            make_pair(standardSmallBin, "standard-small-bin"),
            make_pair(standardSmallSq, "standard-small-sq"),
            make_pair(standardBigBin, "standard-big-bin"),
            make_pair(standardBigSq, "standard-big-sq"),
    };
    for (auto & array : arrays) {
        text_name = array.second;
        iteratePatterns(func, array.first);
    }
}

// Итерация по алгоритмам поиска подстрок
void iterateAlgorithms() {
    pair<vector<int> (*)(string, string), const char *> sorts[] = {
            make_pair(naive, "naive"),
            make_pair(kmpStandard, "kmp-standard"),
            make_pair(kmpRefined, "kmp-refined"),
    };
    for (auto & sort : sorts) {
        algorithm_name = sort.second;
        iterateTexts(sort.first);
    }
}

// Исполнение выбраного кейса
void executeCase(std::string filename) {
    results.open(filename);
    iterateAlgorithms();
    results.close();
}

int main() {
    input.open("../input.txt", std::ios_base::beg);
    output.open("../output.txt", std::ios_base::beg);

    executeCase("../data.csv");
    return 0;
}
