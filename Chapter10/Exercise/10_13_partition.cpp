#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
using namespace std;

bool largerThanFive(const string &s) {
    return s.size() >= 5;
}

int main() {
    vector<string> words{"rad", "the", "quick", "rad", "fox", "jumps", "over", "the", "slow", "rad", "turtle", "rad", "the"};
    auto end_larger = partition(words.begin(), words.end(), largerThanFive);
    for (auto it = words.cbegin(); it != end_larger; ++it) {
        cout << *it << " ";
    }
    return 0;
}