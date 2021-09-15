#include "String.h"
#include <vector>
#include <iostream>
using namespace std;
int main() {
    vector<String> vs;
    String s1("first");
    vs.push_back(s1);
    String s2("second");
    vs.push_back(s2);
    s1+s2;
    print(s1);
    return 0;
}