#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector<int> nums1{1,2,3,4,5,6};
    int nums2[nums1.size()];
    for (unsigned i = 0; i < nums1.size(); i++) {
        nums2[i] = nums1[i];
        cout << nums2[i] << " ";
    }
    cout << endl;
    return 0;
}
