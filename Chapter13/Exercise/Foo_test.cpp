#include "Foo.h"
#include <iostream>
using namespace std;

int main() {
    Foo a(vector<int>{6,2,4,12,4,1});
    a.sorted();
    //Foo b = Foo(vector<int>{3,2,1}).sorted();
    print(a);
    cout << endl;
    //print(b);
    return 0;
}