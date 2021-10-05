#include <iostream>
using namespace std;

struct absInt {
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

int main() {
    int i = -42;
    absInt absObj;
    int ui = absObj(i);
    cout << i << endl;
    cout << ui << endl;
    return 0;
}