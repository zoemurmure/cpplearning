#include <iostream>
#include <vector>
using namespace std;

void readIn(istream& in, vector<int>* pVec) {
    int i;
    while (in >> i) {
        pVec->push_back(i);
    }
}

void print(const vector<int>* pVec) {
    for (auto iter = pVec->cbegin(); 
        iter != pVec->cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

vector<int>* allocVec() {
    return new vector<int>;
}

int main() {
    vector<int>* pVec = allocVec();
    readIn(cin, pVec);
    print(pVec);
    delete pVec;
    return 0;
}