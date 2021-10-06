#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
using namespace std;

class ShorterString {
public:
    bool operator()(const string &s1, const string &s2) const {
        return s1.size() < s2.size();
    }
};

class SizeComp {
public:
    SizeComp(size_t n): sz(n) { }
    bool operator()(const string &s) const {
        return s.size() >= sz;
    }
private:
    size_t sz;
};

class PrintString {
public:
    void operator()(const string &s) const {
        cout << s << " ";
    }
};

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
    stable_sort(words.begin(), words.end(), ShorterString());
    auto wc = find_if(words.begin(), words.end(), SizeComp(sz));
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;

    for_each(wc, words.end(), PrintString());
    cout << endl;
}

int main() {
    vector<string> words{"rad", "the", "quick", "rad", "fox", "jumps", "over", "the", "slow", "rad", "turtle", "rad", "the"};
    biggies(words, 5);
    return 0;
}