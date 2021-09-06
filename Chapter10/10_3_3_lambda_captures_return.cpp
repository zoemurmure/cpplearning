#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
using namespace std;

void fcn1() {
    size_t v1 = 42;
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f();
    cout << j << endl;
}

void fcn2() {
    size_t v1 = 42;
    auto f2 = [&v1] { return v1; };
    v1 = 0;
    auto j = f2();
    cout << j << endl;
}

void fcn3() {
    size_t v1 = 42;
    auto f = [v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f();
    cout << j << endl;
}

void fcn4() {
    size_t v1 = 42;
    auto f2 = [&v1] { return ++v1; };
    v1 = 0;
    auto j = f2();
    cout << j << endl;
}

int main() {
    fcn4();

    vector<int> nums{1,3,45,-2,-433,4,-2};
    transform(nums.begin(), nums.end(), nums.begin(),
        [](int n) -> int 
        { if (n < 0) return -n; else return n; });
    for (int i : nums) {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}