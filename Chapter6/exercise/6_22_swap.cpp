#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap(int *&a, int *&b) {
    int *t = a;
    a = b;
    b = t;
}

int main() {
    int a, b;
    int *m = &a, *n = &b;
    cin >> a >> b;

    cout << *m << " " << *n << endl;
    swap(m, n);
    cout << *m << " " << *n << endl;
    return 0;
}
