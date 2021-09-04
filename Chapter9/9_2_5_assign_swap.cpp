#include <list>
#include <string>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>
using std::list; using std::string;
using std::vector; using std::deque;
using std::forward_list; using std::array;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
    array<int, 10> a1 = {0,1,2,3,4,5,6,7,8,9};
    array<int, 10> a2 = {0};
    a1 = a2;
    //a2 = {0}; // error

    list<string> names;
    vector<const char*> oldstyle;
    //names = oldstyle; // error: container types don't match
    names.assign(oldstyle.cbegin(), oldstyle.cend());

    list<string> slist1(1);
    slist1.assign(10, "Hiya!");

    vector<string> svec1(10);
    vector<string> svec2(24);
    swap(svec1, svec2);
    return 0;
}