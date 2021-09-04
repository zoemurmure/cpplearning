#include <forward_list>
#include <iostream>
using std::forward_list;
using std::cin; using std::cout; using std::endl;

int main() {
    forward_list<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto prev = vi.before_begin();
    auto curr = vi.begin();
    while (curr != vi.end()) {
        if (*curr % 2) {
            curr = vi.insert_after(prev, *curr);
            //curr += 2;
            prev = ++curr;
            ++curr;
        } else {
            curr = vi.erase_after(prev);
        }
    }

    for (auto i : vi) {
        cout << i << " ";
    }

    return 0;
}