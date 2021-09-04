#include <string>
#include <iostream>
using std::string;
using std::cin; using std::cout; using std::endl;

int main() {
    const char *cp = "Hello World!!!";
    char noNull[] = {'H', 'i'};

    string s1(cp);
    cout << s1 << endl;

    string s2(noNull, 2);
    cout << s2 << endl;

    string s3(noNull);
    cout << s3 << endl;  // undefined

    string s4(cp + 6, 5);
    cout << s4 << endl;

    string s5(s1, 6, 5);
    cout << s5 << endl;

    string s6(s1, 6);
    cout << s6 << endl;

    string s7(s1, 6, 20);
    cout << s7 << endl;

    string s8(s1, 16);
    cout << s8 << endl;  // out_of_range
    return 0;
}