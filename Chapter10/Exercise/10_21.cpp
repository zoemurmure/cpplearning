// 没看懂这道题什么意思，瞎写的
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
using namespace std;

int main() {
    int i = 6;
    auto f = [&i]() -> bool
        { if (i > 0) {--i; return true;} else return false;};
    while (i) {
        f();
        cout << i << endl;
    }
    f();
    cout << i << endl;
    return 0;
}