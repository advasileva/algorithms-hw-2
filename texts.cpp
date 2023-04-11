#include <random>

using namespace std;

int SMALL_RANGE = 10000;
int BIG_RANGE = 100000;

char randBin() {
    return std::rand() % 2 + '0';
}

char randSq() {
    return std::rand() % 4 + '0';
}

string getStandardSmall(char (rand)()) {
    srand((unsigned) time(NULL));
    string ans = string(SMALL_RANGE, ' ');
    for (int i = 0; i < SMALL_RANGE; ++i) {
        ans[i] = rand();
    }
    return ans;
}

string getStandardBig(char (rand)()) {
    srand((unsigned) time(NULL));
    string ans = string(BIG_RANGE, ' ');
    for (int i = 0; i < BIG_RANGE; ++i) {
        ans[i] = rand();
    }
    return ans;
}

vector<int> getWildCards() {
    srand((unsigned) time(NULL));
    vector<int> wildcards;
    for (int i = 0; i < 4; ++i) {
        wildcards.push_back(rand() % 3000);
    }
    return wildcards;
}

string standardSmallBin = getStandardSmall(randBin);
string standardSmallSq = getStandardSmall(randSq);
string standardBigBin = getStandardBig(randBin);
string standardBigSq = getStandardBig(randSq);
vector<int> wildcard = getWildCards();

vector<pair<pair<string, int>, string>> getTexts() {
    vector<pair<pair<string, int>, string>> arrays;
    for (int i = 0; i < 5; ++i) {
        arrays.push_back(make_pair(make_pair(standardSmallBin, i), "wildcard-" + std::to_string(i) + "-small-bin"));
        arrays.push_back(make_pair(make_pair(standardSmallSq, i), "wildcard-" + std::to_string(i) + "-small-sq"));
        arrays.push_back(make_pair(make_pair(standardBigBin, i), "wildcard-" + std::to_string(i) + "-big-bin"));
        arrays.push_back(make_pair(make_pair(standardBigSq, i), "wildcard-" + std::to_string(i) + "-big-sq"));
    }
    return arrays;
}
