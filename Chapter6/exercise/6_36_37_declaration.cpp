#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 6.36
string (&func(int i))[10];
// 6/37
using strArr = string[10];
strArr& func2(int i);

auto func3(int i) -> string(&)[10];

string s[10](10, 0);
declytype(s) &func4(int i);


int main(int argc, char **argv) {
    
    return 0;
}
