#include <vector>
#include <iostream>
#include <list>
using std::vector; using std::list;
using std::cin; using std::cout;
using std::endl;

bool equal(const vector<int>&, const list<int>&);

int main() {
    vector<int> a = {1,2,3,4,5};
    list<int> b = {1,2,3,4,5};
    cout << equal(a, b) << endl;
    return 0;
}

bool equal(const vector<int> &va, const list<int> &lb) {
    vector<int> vt(lb.cbegin(), lb.cend());
    return (va == vt);
}