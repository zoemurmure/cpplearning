#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
using namespace std;

template <typename T, typename P>
T find(T beg, T end, const P &v) {
    auto it = beg;
    for (; it != end; ++it) {
        if (*it == v)
            break;
    }
    return it;
}

int main() {
    vector<int> vi{1, 2, 3, 4, 5, 6};
    auto result = find(vi.begin(), vi.end(), 11);
    if (result != vi.end())
        cout << *result << endl;
    else
        cout << "Not find" << endl;
    return 0;
}