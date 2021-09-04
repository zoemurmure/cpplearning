#include <deque>
#include <string>
using std::string; using std::deque;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
    deque<string> ds;
    string word;
    while (cin >> word) {
        ds.push_back(word);
    }

    for (auto iter = ds.cbegin(); iter != ds.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}