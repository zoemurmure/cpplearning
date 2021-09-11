#include <memory>
#include <iostream>
using namespace std;

int main() {
    typedef unique_ptr<int> IntP;
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);

    //IntP p0(ix);
    IntP p1(pi);
    IntP p2(pi2);
    IntP p3(&ix);
    IntP p4(new int(2048));
    IntP p5(p2.get());

    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p3 << endl;
    cout << *p4 << endl;
    cout << *p5 << endl;
    return 0;
}