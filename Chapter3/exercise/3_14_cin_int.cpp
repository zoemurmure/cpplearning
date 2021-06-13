#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    int i;
    vector<int> nums;
    while (cin >> i) {
        nums.push_back(i);
    }

    return 0;
}
