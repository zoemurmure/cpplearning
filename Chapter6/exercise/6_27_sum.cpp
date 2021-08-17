#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sum(initializer_list<int> nums) {
    int s = 0;
    for (const auto n : nums)
        s += n;
    return s;
}

int main(int argc, char **argv) {
    cout << 11234+423+6354 << endl;
    cout << sum({11234, 423, 6354}) << endl;
    return 0;
}
