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
        c = toupper(c);
    }

    cout << s << endl;
    return 0;
}
