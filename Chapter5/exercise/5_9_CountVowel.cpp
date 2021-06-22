#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    string text;
    getline(cin, text);

    for (auto c : text) {
        if (c == 'a') {
            ++aCnt;
        } else if (c == 'e') {
            ++eCnt;
        } else if (c == 'i') {
            ++iCnt;
        } else if (c == 'o') {
            ++oCnt;
        } else if (c == 'u') {
            ++uCnt;
        }
    }

    cout << aCnt << " " << eCnt << " " << iCnt << " "
        << oCnt << " " << uCnt << endl;
    return 0;
}
