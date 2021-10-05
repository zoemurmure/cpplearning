#include <algorithm>
#include <vector>
#include "PrintString.h"
using namespace std;

int main() {
    string s = "test";
    PrintString printer;
    printer(s);
    PrintString errors(cerr, '\n');
    errors(s);

    vector<string> vs{"one", "two", "three"};
    for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
    return 0;
}