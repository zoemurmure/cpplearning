#include <iostream>
using namespace std;

template <typename T, size_t N> constexpr
size_t arr_size(T (&arr)[N]) {
    return N;
}

int main() {
    int ai[] = {1,2,3,4,5,6,7};
    cout << arr_size(ai) << endl;
    return 0;
}