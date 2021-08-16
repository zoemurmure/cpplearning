#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print1(const char *cp) {
    if (cp)
        while (*cp)
            cout << *cp++;
}

void print2(const int *beg, const int*end) {
    while (beg != end)
        cout << *beg++ << endl;
}

void print3(const int ia[], size_t size) {
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << endl;
    }
}
// 数组引用形参，&arr两端的括号不可省略
// 只能作用于大小为10的数组
void print4(int (&arr)[10]) {
    for (auto elem : arr)
        cout << elem << endl;
}


int main() {
    int i = 0;
    int j[2] = {0, 1};
    int k[10] = {0,1,2,3,4,5,6,7,8,9};
    print2(begin(j), end(j));
    print3(j, end(j) - begin(j));
    //print4(&i);     // Wrong
    //print4(j);      // Wrong
    print4(k);      // Right

    return 0;
}
