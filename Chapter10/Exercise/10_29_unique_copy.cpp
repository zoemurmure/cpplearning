#include <algorithm>
#include <list>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main() {
    vector<int> a{1,2,3,4,5};
    list<int> b;
    unique_copy(a.cbegin(), a.cend(), back_inserter(b));
    for (auto i: b)
        cout << i << " ";
    cout << endl;
    return 0;
}