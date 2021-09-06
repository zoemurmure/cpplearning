#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    list<int> lst = {1,2,3,4};
    list<int> lst2, lst3;
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    for (auto i : lst2) 
        cout << i << " ";
    cout << endl;
    for (auto i : lst3) 
        cout << i << " ";
    cout << endl;
    return 0;
}