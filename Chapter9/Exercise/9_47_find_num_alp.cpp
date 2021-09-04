#include <string>
#include <iostream>
using std::string;
using std::cin; using std::cout; using std::endl;

const string NUMS{"1234567890"};
const string ALPS{"qwertyuiopasdfghjklzxcvbnm"
                  "QWERTYUIOPASDFGHJKLZXCVBNM"};

void findNumAlp_v1(const string &s) {
    string::size_type pos = 0;
    while ((pos = s.find_first_of(NUMS, pos)) != string::npos) {
        cout << s[pos] << " ";
        ++pos;
    }
    cout << endl;
}

void findNumAlp_v2(const string &s) {
    string::size_type pos = 0;
    string::size_type start = 0;
    while((pos = s.find_first_not_of(NUMS, pos)) != string::npos) {
        while (start < pos) {
            cout << s[start++] << " ";
        }
        ++pos;
        ++start;
    }
    while (start < s.size()) {
        cout << s[start++] << " ";
    }
    cout << endl;
}

int main() {
    string s{"ab2c3d7R4E6"};
    findNumAlp_v1(s);
    findNumAlp_v2(s);
    return 0;
}