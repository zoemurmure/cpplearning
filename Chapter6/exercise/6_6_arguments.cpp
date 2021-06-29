#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

void arguments(int n) {
    cout << "Parameter is: " << n << endl;
    double d = 3.14;
    static double t = 3.14;
    d += 1;
    t += 1;
    cout << "loca parameter is: " << d << endl;
    cout << "static local parameter is: " << t << endl;
    return;
}

int main() {
    arguments(123);
    arguments(123);
    return 0;
}
