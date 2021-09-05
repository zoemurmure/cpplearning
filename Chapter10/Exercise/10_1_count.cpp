#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    vector<int> vec;
    int n;

    while (cin >> n) {
        vec.push_back(n);
    }

    int val = 3;
    cout << val << " appears " 
        << count(vec.cbegin(), vec.cend(), val) 
        << " times" << endl;
    return 0;
}