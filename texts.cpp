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

string standardSmallBin = getStandardSmall(randBin);
string standardSmallSq = getStandardSmall(randSq);
string standardBigBin = getStandardBig(randBin);
string standardBigSq = getStandardBig(randSq);