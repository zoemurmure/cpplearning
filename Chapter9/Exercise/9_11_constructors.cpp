#include <vector>
#include <iostream>
using std::vector;
using std::cin; using std::cout; using std::endl;

int main() {
    vector<int> a{1,2,3};
    vector<int> b = {1,2,3,4};

    vector<int> c(a);
    vector<int> d = b;

    vector<int> e;

    vector<int> f(a.begin(), a.end());

    vector<int> g(10);

    vector<int> h(10, 2);
    return 0;
}