#include <string>
#include <iostream>
using std::string;
using std::cin; using std::cout; using std::endl;

int main () {
    int i = 42;
    string s = std::to_string(i);
    double d = std::stod(s);

    
    string s2 = "test number: 0x54";
    i = std::stoi(s2.substr(s2.find_first_of("+-.0123456789")), nullptr, 16);
    cout << i << endl;

    return 0;
}