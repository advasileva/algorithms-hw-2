#include <algorithm>
#include <vector>

std::vector<int> naive(std::string text, std::string pattern) {
    int k;
    std::vector<int> occurrences;

    for (int i = 0; i < text.size(); ++i) {
        k = i;
        while (k < text.size() && k - i < pattern.size()  && (text[k] == pattern[k - i] || pattern[k - i] == '?')) {
            k++;
        }
        if (k - i == pattern.size()) {
            occurrences.push_back(i);
        }
    }

    return occurrences;
}