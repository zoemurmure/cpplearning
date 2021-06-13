#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    string s;
    getline(cin, s);

    decltype(s.size()) punct_cnt = 0;
    for (auto c : s) {
        if (ispunct(c)) {
            ++punct_cnt;
        }
    }
    cout << punct_cnt << " punctation characters in " << s << endl;
    return 0;
}
