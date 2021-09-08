#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

string &trimWord(string &s) {
    string alpha{"qwertyuiopasdfghjklzxcvbnm"};
    for (auto &c : s) {
        c = tolower(c);
    }
    while (string::npos !=  s.find_first_not_of(alpha)) {
       s.erase(s.find_first_not_of(alpha), 1);
    }
    return s;
}

int main() {
    map<string, size_t> word_count;
    set<string> exclude = {"the", "but", "and", "or", "an", "a"};
    string word;
    ifstream in("114text");

    while (in >> word) {
        trimWord(word);
        if (word != "" && exclude.find(word) == exclude.end())
            ++word_count[word];
    }
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}