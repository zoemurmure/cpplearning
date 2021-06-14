#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    const char s1[] = "test";
    const char s2[] = "test";
    if (strcmp(s1, s2) == 0) 
        cout << "Equal" << endl;
    else if (strcmp(s1, s2) > 0) 
        cout << s1 << " is bigger than " << s2 << endl;
    else
        cout << s2 << " is bigger than " << s1 << endl;
    return 0;
}
