#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

bool str_subrange(const string &str1, const string &str2) {
    if (str1.size() == str2.size()) 
        return str1 == str2;
    auto size = (str1.size() < str2.size()) 
                ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

// return a copy
string make_plural(size_t ctr, const string &word,
                            const string &ending) {
    return (ctr > 1) ? word + ending : word;
}

// return a reference
const string &shroterString(const string &s1, const string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}

// DISASTER: return a reference to a local object
//const string &manip() {
//    string ret;
//    // transform ret in some way
//    if (!ret.empyt())
//        return ret;
//    else
//        return "Empty";
//}

// can assign to the result of a function
// that returns a reference to nonconst
char &get_val(string &str, string::size_type ix) {
    return str[ix];
}

// functions can return a braced list of values
vector<string> process() {
    string expected = "test1";
    string actual = "test2";

    if (expected.empty()) 
        return {};
    else if (expected == actual)
        return {"functionX", "okay"};
    else
        return {"functionX", expected, actual};
}

// Recursion
int factorial(int val) {
    if (val > 1) 
        return factorial(val-1) * val;
    return 1;
}

int main(int argc, char **argv) {
    string s("a value");
    cout << s << endl;
    get_val(s, 0) = 'A';
    cout << s << endl;

    if (s == "")
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;

    return 0;
}
