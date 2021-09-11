#include <iostream>
using namespace std;

#define STR_LEN 25

int main() {
    char *s = new char[STR_LEN];

    cin.get(s, STR_LEN);
    cout << s << endl;
    return 0;
}