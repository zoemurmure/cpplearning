#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec{1,2,3,4,5,6,7,8,9,0};
    for (auto iter = vec.crbegin(); 
         iter != vec.crend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    for (auto iter = vec.cend()-1;
         iter != vec.cbegin()-1; --iter) {
        cout << *iter << " ";
    }
    return 0;
}