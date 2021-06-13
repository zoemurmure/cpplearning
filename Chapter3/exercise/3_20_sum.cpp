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
    unsigned i;

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
    for (i = 0; i < nums.size() - 1; i++) {
        cout << nums[i] + nums[i+1] << " ";    
    }
    cout << endl;
    for (i = 0; i < nums.size()/2; i++) {
        cout << nums[i] + nums[nums.size()-1-i] << " ";
    }
    if (i == nums.size()-1-i)
        cout << nums[i];
    cout << endl;
    return 0;
}
