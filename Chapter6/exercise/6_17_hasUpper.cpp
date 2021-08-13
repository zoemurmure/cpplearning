#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

bool hasUpper(const string& s) {
    bool result = false;
    for (auto c : s) {
        if (isupper(c)) {
            result = true;
            break;
        }
    }
    return result;
}

void tolower(string& s) {
    for (auto &c : s) {
        c = tolower(c);
    }
    return;
}

int main() {
    string test_str = "cawdohfDFOACcdwWW";
    cout << "Test string is: " << test_str << endl;
    cout << hasUpper(test_str) << endl;
    tolower(test_str);
    cout << test_str << endl;
    return 0;
}
