#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    int nums1[] = {1,2,3,4,5,6};
    vector<int> nums2(nums1, nums1+6);
    for (auto i : nums2) 
        cout << i << " ";
    cout << endl;
    return 0;
}
