#include <vector>
#include <iostream>
#include <string>
using std::vector; using std::string;
using std::cin; using std::cout; using std::endl;

int main() {
    vector<int> c{1,2,3,4,5,6};

    if (!c.empty()) {
        auto val1 = *c.begin(), val2 = c.front();
        auto last = c.end();
        auto val3 = *(--last);
        auto val4 = c.back();

        c.front() = 42;
        auto &v = c.back();
        v = 1024;
        auto v2 = c.back();
        v2 = 0;

        vector<string> svec;
        cout << svec[0];
        //cout << svec.at(0);
    }
    return 0;
}