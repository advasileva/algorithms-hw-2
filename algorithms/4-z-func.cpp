#include <algorithm>
#include <vector>
#include <string>

std::vector<int> zFunction(std::string text, std::string pattern) {
    std::vector<int> occurrences;

    if (pattern.find('?') != std::string::npos) {
        int found = pattern.find('?');
        for (char letter : maxAlph) {
            pattern[found] = letter;
            std::vector<int> extend = zFunction(text, pattern);
            occurrences.insert(occurrences.end(), extend.begin(), extend.end());
        }
        return occurrences;
    }

    int l = 0, r = 0;
    std::string s = pattern + "#" + text;
    std::vector<int> z(s.size());
    for (int i = 1; i < s.size(); ++i) {
        z[i] = std::max(0, std::min(r - i + 1, z[i - l]));
        while (i + z[i] < s.size() && s[z[i]] == s[z[i] + i]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
        if (z[i] == pattern.size()) {
            occurrences.push_back(i - pattern.size() - 1);
        }
    }

    return occurrences;
}