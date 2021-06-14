#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main() {
    int ia[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    cout << "Version 1: for" << endl;
    for (int (&i)[4] : ia) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Version 2: Ordinary for_index" << endl;
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 4; j++) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Version 3: Ordinary for_pointer" << endl;
    for (int (*i)[4] = begin(ia); i != end(ia); i++) {
        for (int *j = begin(*i); j != end(*i); ++j) {
            cout << *j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
