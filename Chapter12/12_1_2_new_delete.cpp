#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    //int *pi = new int;  // uninitialized
    int *pi = new int(1024);
    string *ps = new string(10, '9');
    vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};
    cout << *pi << endl;

    int i, *pi1 = &i, *pi2 = nullptr;
    double *pd = new double(33), *pd2 = pd;
    delete pd;
    delete pd2; // undefined
    const int *pci = new const int(1024);
    delete pci;
    return 0;
}