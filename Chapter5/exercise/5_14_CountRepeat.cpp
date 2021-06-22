#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    unsigned maxCount = 0, cntCount = 0;
    string maxString, preString, cntString;

    while (cin >> cntString) {
        if (preString == cntString) {
            ++cntCount;
        } else {
            cntCount = 1;
            preString = cntString;
        }
        if (cntCount > maxCount) {
            maxCount = cntCount;
            maxString = cntString;
        }
    }
    if (maxCount > 1) {
        cout << maxString << ": " << maxCount << endl;
    } else {
        cout << "There is no repeat word in this sentence." << endl;
    }
    return 0;
}
