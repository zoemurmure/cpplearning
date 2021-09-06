#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
#include <functional>
using namespace std;

bool isShorter(const string &s, string::size_type sz) {
    return s.size() <= sz;
}

int main() {
    vector<string> words{"rad", "the", "quick", "rad", "fox", "jumps", "over", "the", "slow", "rad", "turtle", "rad", "the"};
    int n = count_if(words.cbegin(), words.cend(),
            bind(isShorter, placeholders::_1, 6));
    cout << n << endl;
    return 0;
}