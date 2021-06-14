#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main() {
    int nums[] = {34, 23, 234, 12, 44};
    for (int *it = begin(nums); it != end(nums); ++it) {
        *it = 0;
    }
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
