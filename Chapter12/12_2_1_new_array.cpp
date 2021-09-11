#include <iostream>
#include <memory>
using namespace std;

int main() {
    int *pia = new int[42];

    typedef int arrT[42];
    int *p = new arrT;

    int *pia2 = new int[10]();
    int *pia3 = new int[10]{1,2,3,4,5,6,7,8,9,0};

    char *cp = new char[0];

    unique_ptr<int[]> up(new int[10]);
    for (size_t i = 0; i < 10; ++i) {
        up[i] = i;
    }
    up.release();

    shared_ptr<int> sp(new int[10], [](int *p){ delete [] p; });
    for (size_t i = 0; i < 10; ++i) {
        *(sp.get()+i) = i;
    }
    sp.reset();

    delete [] pia;
    delete [] p;
    delete [] pia2;
    delete [] pia3;
    delete [] cp;
    return 0;
}