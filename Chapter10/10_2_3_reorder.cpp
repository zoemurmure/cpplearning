// 不知道为什么打印出来的unique之后的字符串有问题
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

ostream &print(ostream& out, const vector<string>& vec) {
    for (const auto &s : vec) {
        out << s << " ";
    }
    return out;
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    cout << "After sort  : ";
    print(cout, words) << words.size() << endl;
    auto end_unique = unique(words.begin(), words.end());
    cout << "After unique: ";
    print(cout, words) << words.size() << endl;
    words.erase(end_unique, words.end());
    cout << "After erase : ";
    print(cout, words) << words.size() << endl;
}

int main() {
    vector<string> words{"rad", "the", "quick", "rad", "fox", "jumps", "over", "the", "slow", "rad", "turtle", "rad", "the"};
    elimDups(words);
    for (auto word : words) {
        cout << word << " ";
    }
    return 0;
}