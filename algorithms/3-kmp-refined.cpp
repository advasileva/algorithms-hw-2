#include <algorithm>
#include <vector>
#include <string>

std::vector<int> kmpRefined(std::string text, std::string pattern) {
    std::vector<int> occurrences;

    if (pattern.find('?') != std::string::npos) {
        int found = pattern.find('?');
        for (char letter : maxAlph) {
            pattern[found] = letter;
            std::vector<int> extend = kmpRefined(text, pattern);
            occurrences.insert(occurrences.end(), extend.begin(), extend.end());
        }
        return occurrences;
    }

    int k;
    int n = text.size(), m = pattern.size();
    std::vector<int> br(m);
    br[0] = 0;
    k = 0;
    for (int i = 1; i < m; ++i) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = br[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            k++;
        }
        br[i] = k;
    }

    std::vector<int> brs(m);
    brs[0] = 0;
    for (int i = 1; i < m; ++i) {
        if (pattern[br[i]] != pattern[i + 1]) {
            brs[i] = br[i];
        } else {
            brs[i] = brs[br[i - 1]];
        }
    }

    k = 0;
    for (int i = 0; i < n; ++i) {
        while (k > 0 && pattern[k] != text[i]) {
            k = brs[k - 1];
        }
        if (pattern[k] == text[i]) {
            k++;
        } else if (k > 0) {
            k = brs[k - 1];
        }
        if (k == m) {
            occurrences.push_back(i - m + 1);
            k = brs[m - 1];
        }
    }

    return occurrences;
}