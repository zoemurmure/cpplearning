#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <iterator>
using namespace std;

int main() {
    vector<int> vec(10);
    fill(vec.begin(), vec.end(), 5);

    // dangerous
    fill_n(vec.begin(), vec.size(), 7);
    // back_inserter
    fill_n(back_inserter(vec), 3, 21);

    return 0;
}