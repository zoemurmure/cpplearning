#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
using namespace std;

int main() {
    auto f = [](int a, int b) { return a + b; };
    cout << f(1,2) << endl;
    return 0;
}