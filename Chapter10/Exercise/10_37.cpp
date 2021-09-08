#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

int main() {
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    list<int> lst(vec.crbegin()+2, vec.crend()-3);
    for (const auto i : lst) 
        cout << i << endl;
    return 0;
}