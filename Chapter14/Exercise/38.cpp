#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class LargerThan {
public:
    LargerThan(size_t a, size_t b): min(a), max(b) { }
    bool operator()(string &s) const {
        return (s.size() >= min) && (s.size() <= max);
    }
private:
    size_t min, max;
};

int main() {
    ifstream in("test38");
    vector<string> words;
    string word;
    while (in >> word) {
        words.push_back(word);
    }
    cout << count_if(words.begin(), words.end(), LargerThan(1, 10)) << endl;
    return 0;
}