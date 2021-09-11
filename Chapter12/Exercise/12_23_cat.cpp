#include <iostream>
#include <string>
#include <cstring>
#include <memory>
using namespace std;

unique_ptr<char[]> charCat(const char *s1, const char *s2) {
    unique_ptr<char[]> ret(new char[strlen(s1)+strlen(s2)+1]);
    strcpy(ret.get(), s1);
    strcat(ret.get(), s2);
    
    return ret;
}

int main() {
    unique_ptr<char[]> s = charCat("hello ", "world");
    cout << s.get() << endl;
    return 0;
}