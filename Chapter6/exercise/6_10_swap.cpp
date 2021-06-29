#include <iostream>
using std::cout;
using std::endl;

void swap(int *num1, int *num2) {
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
    return;
}

int main() {
    int a = 12, b = 45;
    swap(&a, &b);
    cout << a << " " << b << endl;
    return 0;
}
