#include <iostream>
#include <string>
#include <vector>
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
const string &shroterString(const string &s1, cosnt string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}

// DISASTER: return a reference to a local object
const string &manip() {
    string ret;
    // transform ret in some way
    if (!ret.empyt())
        return ret;
    else
        return "Empty";
}

int main(int argc, char **argv) {
    
    return 0;
}
