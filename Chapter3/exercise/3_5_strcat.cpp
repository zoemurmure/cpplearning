#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    string sentence = "";
    string s;
    while (cin >> s) {
        sentence += s + " ";
    }
    cout << sentence << endl;
    return 0;
}
