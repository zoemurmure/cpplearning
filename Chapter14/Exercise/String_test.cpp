#include "String.h"
#include <vector>
#include <iostream>
using namespace std;
int main() {
    vector<String> vs;
    String s1("first");
    String s2("second");
    vs.push_back(s1);
    vs.push_back(s2);
    cout << s1;
    //s1+s2;
    //print(s1);
    return 0;
}