#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(const int ia[10]) {
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}

int main() {
    int i[10] = {0,1,2,3,4,5,6,7,8,9};
    print(i);
    return 0;
}
