#include <iostream>
#include <vector>
#include <memory>
using namespace std;

void readIn(istream& in, shared_ptr<vector<int>> pVec) {
    int i;
    while (in >> i) {
        pVec->push_back(i);
    }
}

void print(const shared_ptr<vector<int>> pVec) {
    for (auto iter = pVec->cbegin(); 
        iter != pVec->cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

shared_ptr<vector<int>> allocVec() {
    return make_shared<vector<int>>();
}

int main() {
    shared_ptr<vector<int>> pVec = allocVec();
    readIn(cin, pVec);
    print(pVec);
    return 0;
}