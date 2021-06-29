#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    string pre, cur;
    bool ifRepeat = false;
    while (cin >> cur) {
        if (cur == pre) {
            cout << "Repeat string is: " << cur << endl;
            ifRepeat = true;
            break;
        } else {
            pre = cur;
        }
    }
    if (!ifRepeat) {
        cout << "NO REPEAT!" << endl;
    }
    return 0;
}
