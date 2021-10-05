#include <vector>
#include "ReadString.h"
using namespace std;

int main() {
    vector<string> vs;
    ReadString rs;
    for (string s = rs(cin); s != ""; s = rs(cin)) {
        vs.push_back(s);
        cout << s << endl;
    }

    return 0;
}