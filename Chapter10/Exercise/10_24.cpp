#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
#include <functional>
using namespace std;

bool check_size(const string &s, string::size_type sz) {
    return s.size() < sz;
}

int main() {
    vector<int> nums{0,1,2,3,4,5,6,7,8,9};
    string s{"test"};
    auto pos = find_if(nums.cbegin(), nums.cend(),
        bind(check_size, s, placeholders::_1));
    cout << *pos << endl;
    return 0;
}