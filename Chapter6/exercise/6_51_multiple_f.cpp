#include <iostream>
#include <string>
#include <vector>
using namespace std;

void f() { cout << "1" << endl; }
void f(int) { cout << "2" << endl; }
void f(int, int) { cout << "3" << endl; }
void f(double, double) { cout << "4" << endl;}


int main(int argc, char **argv) {
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}
