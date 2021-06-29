#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

long long fact(int n) {
    long long result = 1;
    while (n > 1) {
        result *= n--;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}
