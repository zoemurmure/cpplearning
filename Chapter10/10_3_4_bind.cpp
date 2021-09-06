#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
#include <functional>
using namespace std;

bool check_size(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

int main() {
    auto check6 = bind(check_size, placeholders::_1, 6);
    string s = "hello";
    bool b1 = check6(s);
    cout << b1 << endl;
}