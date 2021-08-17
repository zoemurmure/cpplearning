#include <iostream>
#include <string>
#include <vector>
using namespace std;

void error_msg(initializer_list<string> il) {
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

void error_msg(ErrCode e, initializer_list<string> il) {
    cout << e.msg() << ": ";
    for (const auto &elem : il)
        cout << elem << " ";
    cout << endl;
}

int main(int argc, char **argv) {
    string expected = "secret";
    string actual;
    cin >> actual;
    if (expected != actual)
        error_msg({"functionX", expected, actual});
    else 
        error_msg({"functionX", "okay"});
    return 0;
}
