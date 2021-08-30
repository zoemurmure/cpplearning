#include <iostream>
#include <string>
#include <vector>
using namespace std;

int my_add(int a, int b) {
    return a + b;
}

int my_sub(int a, int b) {
    return a - b;
}

int my_mul(int a, int b) {
    return a * b;
}

int my_div(int a, int b) {
    return a / b;
} 

int main(int argc, char **argv) {
    vector<decltype(my_add)*> v{my_add, my_sub, my_mul, my_div};
    cout << v[0](10, 2) << " " << v[1](10, 2) << " " 
        << v[2](10, 2) << " " << v[3](10, 2) << endl;
    return 0;
}
