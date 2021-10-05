#include <iostream>
using namespace std;

struct ifThenElse {
    using value_type = int;
    value_type operator()(bool test, value_type a, value_type b) {
        if (test) return a;
        else return b;
    }
};

int main() {
    ifThenElse ite;
    cout << ite(true, 1, 2) << endl;

    return 0;
}