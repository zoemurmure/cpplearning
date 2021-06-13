#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2) {
        cout << "Equal" << endl;
    } else {
        if (s1 > s2) {
            cout << s1 << " is bigger" << endl;
        } else {
            cout << s2 << " is bigger" << endl;
        }
    }

    return 0;
}
