#include <string>
#include <vector>
#include <iostream>
using std::string; using std::vector;
using std::cin; using std::cout; using std::endl;

int main() {
    vector<char> vch = {'a', 'b', 'c', 'd'};
    string s(vch.cbegin(), vch.cend());
    cout << s << endl;
}