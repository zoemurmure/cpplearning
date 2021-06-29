#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int called_times() {
    static int t = -1;
    t++;
    return t;
}

int main() {
    cout << called_times() << endl;
    cout << called_times() << endl;
    cout << called_times() << endl;
    cout << called_times() << endl;
    cout << called_times() << endl;
    return 0;
}
