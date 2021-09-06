#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
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

string make_plural(int n, const string &s, const string &t) {
    if (n > 1) {
        return s + t;
    } else {
        return s;
    }
}

void biggies(vector<string> &words, 
            vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(), words.end(), 
        [](const string &a, const string &b)
        { return a.size() < b.size(); });
    auto wc = stable_partition(words.begin(), words.end(), 
        [sz](const string &a) { return a.size() >= sz; });
    auto count = wc - words.begin();
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;

    for_each(words.begin(), wc, 
        [](const string &s) { cout << s << " "; });
    cout << endl;
}

int main() {
    vector<string> words{"rad", "the", "quick", "rad", "fox", "jumps", "over", "the", "slow", "rad", "turtle", "rad", "the"};
    biggies(words, 5);
    return 0;
}