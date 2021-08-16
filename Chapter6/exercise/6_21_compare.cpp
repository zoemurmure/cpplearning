#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compare(const int a, const int *b) {
    return (a > *b) ? a : *b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << compare(a, &b) << endl;
    return 0;
}
