#include <list>
#include <iostream>
using std::list;
using std::cin; using std::cout; using std::endl;

int main() {
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it % 2)
            it = lst.erase(it);
        else {
            cout << *it << " ";
            ++it;
        }
    }
}