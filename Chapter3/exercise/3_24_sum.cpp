#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::cerr;

int main() {
    vector<int> nums;
    int temp;

    while (cin >> temp) {
        nums.push_back(temp);
    }
    if (nums.size() < 1) {
        cerr << "NO NUMBERS!" << endl;
        return -1;
    } else if (nums.size() == 1) {
        cout << nums[0] << endl;
        return 0;
    }
    auto begin = nums.cbegin();
    auto end = nums.cend();
    auto it = begin, jt = end;

    for (it = begin; it+1 != end; ++it) {
        cout << *it + *(it+1) << " ";
    }
    cout << endl;
    for (it = begin, jt = end-1; it < jt; ++it, --jt) {
        cout << *it + *jt << " ";
    }
    if (it == jt) {
        cout << *it;
    }
    cout << endl;
    return 0;
}
