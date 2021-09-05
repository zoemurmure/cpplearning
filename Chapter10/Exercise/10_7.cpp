#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <iterator>
#include <list>
using namespace std;

int main() {
    vector<int> vec; list<int> lst; int i;
    while (cin >> i) {
        lst.push_back(i);
    }
    copy(lst.cbegin(), lst.cend(), vec.begin());

    for (auto i : vec) {
        cout << i << " ";
    }
    return 0;
}