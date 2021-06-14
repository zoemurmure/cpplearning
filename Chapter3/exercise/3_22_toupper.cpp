#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector<string> text{"first line", "second line", "", "thid line"};
    for (auto it = text.begin(); 
        it != text.cend() && !it->empty(); ++it) {
        for (auto jt = (*it).begin(); jt != (*it).end(); ++jt) {
            if (isalpha(*jt)) {
                *jt = toupper(*jt);
            }
        }
        cout << *it << endl;
    }
    return 0;
}
