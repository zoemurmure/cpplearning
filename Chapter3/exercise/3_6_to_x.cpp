#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    string s;
    getline(cin, s);

    for (auto &c : s) {
        if (isalnum(c)) {
            c = 'X';
        }
    }
    cout << s << endl;
    return 0;
}
