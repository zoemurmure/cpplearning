#include <iostream>
#include "Debug.h"
using namespace std;

int main() {
    constexpr Debug io_sub(false, true, false);
    if (io_sub.any()) {
        cerr << "Error 1" << endl;
    }

    constexpr Debug prod(false);
    if (prod.any()) {
        cerr << "Error 2" << endl;
    }

    return 1;
}