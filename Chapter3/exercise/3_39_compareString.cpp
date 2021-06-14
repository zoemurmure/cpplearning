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
    getline(cin, s1);
    getline(cin, s2);
    if (s1 == s2) 
        cout << "Equal" << endl;
    else if (s1 > s2) 
        cout << s1 << " is bigger than " << s2 << endl;
    else
        cout << s2 << " is bigger than " << s1 << endl;
    return 0;
}
