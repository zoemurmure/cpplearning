#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int num;
    vector<int> nums{1,2,3,4,5};
    modulus<int> intModulus;
    while (cin >> num) {
        for (auto i : nums) {
            if (intModulus(num, i) == 0)
                cout << num << " is divisible by " << i << endl;
        }
    }
    return 0;
}