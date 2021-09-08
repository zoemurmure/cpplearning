#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    for (auto r_iter = vec.crbegin();
        r_iter != vec.crend(); ++r_iter) {
        cout << *r_iter << endl;
    }

    string line{"one,two,three,four"};
    auto comma = find(line.cbegin(), line.cend(), ',');
    cout << string(line.cbegin(), comma) << endl;

    auto rcomma = find(line.crbegin(), line.crend(), ',');
    cout << string(rcomma.base(), line.cend()) << endl;
    return 0;
}