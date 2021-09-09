#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        ++(word_count.insert({word, 0}).first->second);
    }

    for (const auto& i : word_count) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}