// 我看的英文版，把习题的意思理解错了
// 不过也没改这个代码
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

int main() {
    const char roster1[] = "this is a test.";
    const char roster2[] = "this is a test.";
    cout << equal(begin(roster1), end(roster1), begin(roster2)) << endl;
    return 0;
}