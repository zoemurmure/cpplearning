#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

double abs(double n) {
    return (n >= 0 ? n : -n);
}

int main() {
    double n;
    cin >> n;
    cout << abs(n) << endl;
    return 0;
}
