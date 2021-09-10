#include <memory>
#include <iostream>

using namespace std;

int main() {
    shared_ptr<int> p(new int(42));
    int *q = p.get();
    {
        shared_ptr<int> t(q);
    }
    *p = 13; // undefined
    cout << *p << endl;
    return 0;
}