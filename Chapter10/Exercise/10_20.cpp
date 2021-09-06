#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
using namespace std;

int main() {
    vector<string> words{"rad", "the", "quick", "rad", "fox", "jumps", "over", "the", "slow", "rad", "turtle", "rad", "the"};
    int n = count_if(words.begin(), words.end(),
        [](const string &s) { return s.size() > 6; });
    cout << n << endl;
    return 0;
}