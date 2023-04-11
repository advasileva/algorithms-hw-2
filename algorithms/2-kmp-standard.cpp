#include <algorithm>
#include <vector>
#include <string>

std::vector<int> kmpStandard(std::string text, std::string pattern) {
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

    std::vector<int> occurrences;

    k = 0;
    for (int i = 0; i < n; ++i) {
        while (k > 0 && pattern[k] != text[i]) {
            k = br[k - 1];
        }
        if (pattern[k] == text[i]) {
            k++;
        }
        if (k == m) {
            occurrences.push_back(i - m + 1);
            k = br[m - 1];
        }
    }

    return occurrences;
}