#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T, size_t N>
T *begin_(T (&arr)[N]) {
    return arr;
}

template <typename T, size_t N>
T *end_(T (&arr)[N]) {
    return arr + N;
}

int main() {
    int ai[] = {1,2,3,4,5};
    for (auto it = begin_(ai); it != end_(ai); ++it) {
        cout << *it << endl;
    } 
    return 0;
}