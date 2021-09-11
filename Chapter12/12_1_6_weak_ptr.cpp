#include <memory>
#include <iostream>
using namespace std;

int main() {
    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p);
    if (shared_ptr<int> np = wp.lock()) {
        cout << *np << endl;
    }

    return 0;
}