#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
    string text;
    getline(cin, text);

    for (auto it = text.begin(); it != text.end(); ++it) {
        switch (*it) {
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
            case 'f': 
            {
                if (it+1 != text.end()) {
                    switch (*(it + 1)) {
                        case 'f':
                            ++ffCnt;
                            break;
                        case 'l':
                            ++flCnt;
                            break;
                        case 'i':
                            ++fiCnt;
                            break;
                        default:
                            break;
                    }
                }
                break;
            }
            default:
                break;
        } 
    }

    cout << aCnt << " " << eCnt << " " << iCnt << " "
        << oCnt << " " << uCnt << " " << ffCnt << " "
        << flCnt << " " << fiCnt <<endl;
    return 0;
}
