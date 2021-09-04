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
    vector<int> v1 = {1,3,5,7,9,12};
    vector<int> v2 = {1,3,9};
    vector<int> v3 = {1,3,5,7};
    vector<int> v4 = {1,3,5,7,9,12};

    cout << (v1 < v2) << endl;
    cout << (v1 < v3) << endl;
    cout << (v1 == v4)<< endl;
    cout << (v1 == v2) << endl;

    return 0;
}