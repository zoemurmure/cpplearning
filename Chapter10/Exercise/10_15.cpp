#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
using namespace std;

int main() {
    int m = 3;
    auto f = [m](int a) { return a + m; };
    cout << f(1) << endl;
    return 0;
}