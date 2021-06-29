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
            if (isupper(cur[0])) {
                cout << "Repeat string is: " << cur << endl;
                ifRepeat = true;
            } else {
                continue;
            }
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
