#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::runtime_error;
int main() {
    int a, b;
    try {
        cin >> a >> b;
        if (b == 0) {
            throw runtime_error("Second number can't be zero");
        }
        cout << a/b << endl;
    } catch (runtime_error err) {
        cout << err.what() << endl;
    }
    return 0;
}
