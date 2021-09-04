#include <list>
#include <string>
#include <vector>
using std::string; using std::vector;
using std::list;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
    list<const char*> lc = {"123", "abc"};
    vector<string> vs;
    vs.assign(lc.begin(), lc.end());
    for (auto s : vs) {
        cout << s << endl;
    }
    return 0;
}