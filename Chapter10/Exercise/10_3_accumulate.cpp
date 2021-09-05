#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

int main() {
    vector<int> vec;
    int n;
    while (cin >> n) {
        vec.push_back(n);
    }
    int sum = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << sum << endl;
    return 0;
}