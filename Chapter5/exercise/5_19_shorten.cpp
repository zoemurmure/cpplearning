#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    string s1, s2;
    do {
        cout << "Enter two string: " << endl;
        if (cin >> s1 >> s2) {
            cout << "Shorten string is: " << 
                (s1.length() < s2.length() ? s1 : s2) << endl;
        }
    } while (cin);
    return 0;
}
