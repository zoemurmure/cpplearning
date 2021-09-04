#include <string>
#include <iostream>
using std::string;
using std::cin; using std::cout; using std::endl;

void replaceStr(string& s, const string &oldVal, 
            const string &newVal) {
    auto start = s.begin();
    for (auto iter = s.begin(); iter != s.end(); ++iter) {
         auto iter2 = oldVal.cbegin();
         for (auto iter3 = iter; 
            iter3 != s.end() && iter2 != oldVal.cend(); 
            ++iter3, ++iter2) {
            if (*iter3 != *iter2) break;
         }
         if (iter2 == oldVal.cend()) {
            auto pos = iter - s.begin();
            s.replace(pos, oldVal.size(), newVal);
         }
    }
}


int main() {
    string s = "This aaa is a aaa test case.";
    string a = "aaa";
    string b = "bbb";
    replaceStr(s, a, b);
    cout << s << endl;
    return 0;
}