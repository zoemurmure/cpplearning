#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;

int main() {
    vector<int> nums{23, 12, 4, 6762, 1022, 7878};
    vector<string> strs{"pooh", "pooh", "booh", "pooh"};

    cout << count_if(nums.begin(), nums.end(), bind(greater<int>(), placeholders::_1, 1024)) << endl;
    cout << *find_if(strs.begin(), strs.end(), bind(not_equal_to<string>(), placeholders::_1, "pooh")) << endl;
    transform(nums.begin(), nums.end(), nums.begin(), bind(multiplies<int>(), placeholders::_1, 2));
    for (auto i : nums) {
        cout << i << " ";
    }
    return 0;
}