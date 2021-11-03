#include "Vec.h"
#include <iostream>
#include <string>
using namespace std;


int main () {
    Vec<int> vs;
    vs.push_back(1);
    vs.pop_back();
    vs.push_back(2);
    vs.push_back(3);
    vs.push_back(3);
    vs.push_back(3);
    vs.push_back(2);
    vs.push_back(3);
    vs.push_back(3);


    for (auto it = vs.begin(); it != vs.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout << vs.size() << " " << vs.capacity() << endl;

    Vec<int> vs2;
    vs2 = vs;
    cout << vs2.size() << " " << vs2.capacity() << endl;

    Vec<int> vs3{1,2,3};
    cout << vs3.size() << " " << vs3.capacity() << endl;
    return 0;
}