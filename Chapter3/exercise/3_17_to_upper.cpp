#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector<string> words;
    string temp;
    while (cin >> temp) {
        words.push_back(temp);
    }
    for (auto &word : words) {
        for (auto &c : word) {
            c = toupper(c);
        }
        cout << word << endl;
    }

    return 0;
}
