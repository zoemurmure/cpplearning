#include "Screen.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Screen<12, 12> s("test");
    cout << s << endl;
    cin >> s;
    cout << s << endl;
    return 0;
}