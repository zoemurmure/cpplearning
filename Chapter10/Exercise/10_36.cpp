#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

int main() {
    list<int> lst{32,45,22,5,0,43,21,1,0,21,222,1};
    auto zero = find(lst.crbegin(), lst.crend(), 0);
    cout << *zero << endl;
    return 0;
}