#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector<int> nums = {1,2,3,4,5,6};
    for (auto &i : nums) {
        if (i % 2) {
            i *= 2;
        }
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
