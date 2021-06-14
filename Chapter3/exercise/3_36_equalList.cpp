#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main() {
    int num1[] = {1, 2, 23, 33, 4, 5, 6};
    int num2[] = {1, 2, 3, 4, 5, 6};
    int *b1 = begin(num1);
    int *b2 = begin(num2);
    int *e1 = end(num1);
    int *e2 = end(num2);
    int *i, *j;
    for (i = b1, j = b2; i < e1 && j < e2 && *i == *j; ++i, ++j) {
    }
    if (i < e1 || j < e2) {
        cout << "Not equal" << endl;
    } else {
        cout << "Equal" << endl;
    }
    return 0;
}
