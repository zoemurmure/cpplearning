#include <iostream>
#include "SmallInt.h"
using namespace std;

int main() {
    SmallInt si;
    si = 4;
    cout << si + 3 << endl;

    SmallInt si2 = 3.14;
    cout << si2 + 3.14 << endl;
    return 0;
}