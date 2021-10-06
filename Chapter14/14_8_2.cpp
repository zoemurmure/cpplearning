#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    plus<int> intAdd;
    negate<int> intNegate;

    int sum = intAdd(10, 20);
    sum = intNegate(sum);
    cout << sum << endl;

    string name1 = "Andy";
    string name2 = "Bill";
    string name3 = "David";

    vector<string *> nameTable{&name1, &name2, &name3};
    sort(nameTable.begin(), nameTable.end(), less<string*>());
    for (auto ptr : nameTable) {
        cout << *ptr << endl;
    }

    return 0;
}