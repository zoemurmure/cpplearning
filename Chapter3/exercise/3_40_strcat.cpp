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
    char s1[] = "My name is ";
    char s2[] = "zoem.";
    char s[50];
    strcpy(s, s1);
    strcat(s, s2);
    cout << s << endl;
    return 0;
}
