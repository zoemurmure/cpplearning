#include <list>
#include <vector>
#include <iostream>
using std::list; using std::vector;
using std::cin; using std::cout; using std::endl;

int main() {
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> iv(ia, ia + sizeof(ia)/sizeof(int));
    list<int> il(ia, ia + sizeof(ia)/sizeof(int));

    auto iter1 = iv.begin();
    while (iter1 != iv.end()) {
        if (*iter1 % 2) {
            cout << *iter1 << " ";
            ++iter1;
        } else {
            iter1 = iv.erase(iter1);
        }
    }
    cout << endl;
    auto iter2 = il.begin();
    while (iter2 != il.end()) {
        if (*iter2 % 2) {
            iter2 = il.erase(iter2);
        } else {
            cout << *iter2 << " ";
            ++iter2;
        }
    }
    cout << endl;
    return 0;
}