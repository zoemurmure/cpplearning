#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector<int> nums{2,43,1,56,2,66,224,98,10,43};
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        *it *= 2;
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
