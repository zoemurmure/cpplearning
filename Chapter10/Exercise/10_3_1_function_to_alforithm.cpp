#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

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
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    stable_sort(words.begin(), words.end(), isShorter);
    print(cout, words);
    return 0;
}