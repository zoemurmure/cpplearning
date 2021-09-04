#include <vector>
#include <iostream>
using std::vector;
using std::cin; using std::cout;
using std::endl;

bool equal(const vector<int>&, const vector<int>&);

int main() {
    vector<int> a = {1,2,3,4,5};
    vector<int> b = a;
    cout << equal(a, b) << endl;
    return 0;
}

bool equal(const vector<int> &a, const vector<int> &b) {
    return (a == b);
}