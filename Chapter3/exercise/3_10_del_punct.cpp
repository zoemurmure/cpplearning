#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    string s, output = "";
    getline(cin ,s);

    for (auto c : s) {
        if (! ispunct(c)) {
            output += c;
        }
    }
    cout << output << endl;
    return 0;
}
