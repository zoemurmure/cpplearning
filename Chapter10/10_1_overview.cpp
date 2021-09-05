#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    vector<int> vec{1,2,3,4,5,6,7,8,9,0};
    int val = 42;
    auto result = find(vec.cbegin(), vec.cend(), val);

    cout << "The value " << val
         << (result == vec.cend() 
            ? " is not present" : " is present") << endl;

    return 0;
}