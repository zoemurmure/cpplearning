#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<int> nums, int n) {
    if (n < 1) return;
    if (n == 1)
        cout << nums[0];
    else {
        print(nums, --n);
        cout << " " << nums[n];
    }

}

int main(int argc, char **argv) {
    vector<int> test{1,2,3,4,5,6,7,8,9};
    print(test, 9);
    return 0;
}
