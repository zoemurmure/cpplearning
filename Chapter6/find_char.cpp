#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

string::size_type find_char(const string &s, char c,
                string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) {
                ret = i;
            }
            ++occurs;
        }
    }
    return ret;
}

int main() {
    string::size_type occurs = 0;
    auto idx = find_char("this is a test sentence.", 'e', occurs);
    cout << idx << " " << occurs << endl;
    return 0;
}
