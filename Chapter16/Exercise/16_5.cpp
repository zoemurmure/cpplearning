#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T, size_t N>
void print(T (&a)[N]) {
    for (auto i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    return;
}

int main() {
    int ai[] = {1,2,3,4,5};
    print(ai);
    char ac[] = "testcase";
    print(ac);
    return 0;
}