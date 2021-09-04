#include <vector>
using std::vector;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
    vector<int> vi{0,1,2,3,4,5,6,7,8,9};
    auto b = vi.begin();
    while (b != vi.end()) {
        ++b;
        b = vi.insert(b, 42);
        ++b;
    }

    for (auto i : vi) {
        cout << i << " ";
    }
    return 0;
}