#include <algorithm>
#include <deque>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main() {
    vector<int> nums{1,2,3,4,5,6,7,8,9};
    deque<int> a, b, c;
    copy(nums.cbegin(), nums.cend(), inserter(a, a.end()));
    copy(nums.cbegin(), nums.cend(), back_inserter(b));
    copy(nums.cbegin(), nums.cend(), front_inserter(c));
    for (auto i = 0; i < nums.size(); ++i) {
        cout << a[i] << " " << b[i] << " " << c[i] << endl;
    }    
    return 0;
}