#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() == s2.size()) {
        cout << "Equal" << endl;
    } else {
        if (s1.size() > s2.size()) {
            cout << "Length of '" << s1 << "' is bigger." << endl;
        } else {
            cout << "Length of '" << s2 << "' is bigger." << endl;
        }
    }
    return 0;
}
