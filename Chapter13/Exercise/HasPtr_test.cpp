#include "HasPtr.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //string s1("test1"), s2("test2");
    //HasPtr hp1(s1), hp2(s2);
    //swap(hp1, hp2);
    vector<HasPtr> vh;
    HasPtr hp1("one"), hp2("two"), hp3("three");
    vh.push_back(hp1);
    vh.push_back(hp2);
    vh.push_back(hp3);
    sort(vh.begin(), vh.end());
    return 0;
}