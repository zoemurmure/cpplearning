#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, sCnt = 0;
    string text;
    while (getline(cin, text)) {
        ++sCnt;
        for (auto c : text) {
            c = tolower(c);
            switch (c) {
                case 'a':
                    ++aCnt;
                    break;
                case 'e':
                    ++eCnt;
                    break;
                case 'i':
                    ++iCnt;
                    break;
                case 'o':
                    ++oCnt;
                    break;
                case 'u':
                    ++uCnt;
                    break;
                case ' ':
                case '\t':
                    ++sCnt;
                    break;
                default:
                    break;
            }
        }
    }

    cout << aCnt << " " << eCnt << " " << iCnt << " "
        << oCnt << " " << uCnt << " " << sCnt << endl;
    return 0;
}
