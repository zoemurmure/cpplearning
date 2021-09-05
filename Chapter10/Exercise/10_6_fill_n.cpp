#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <iterator>
using namespace std;

int main() {
    vector<int> vec(10);
    fill_n(vec.begin(), vec.size(), 0);

    for (auto i : vec) {
        cout << i << " ";
    }
    return 0;
}