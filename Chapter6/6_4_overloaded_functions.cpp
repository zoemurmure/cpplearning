#include <iostream>
#include <string>
#include <vector>
using namespace std;

using Record = int;
using Account = int;
using Phone = long long;
using Name = string;
//Record lookup(const Account&) { return 0; };
//Record lookup(const Phone&) { return 0; };
Record lookup(const Name&) { return 0; };

/* overloading and const parameters */
Record lookup(Phone) { return 0; };
//Record lookup(const Phone) { return 0; };  // redeclare
Record lookup(Phone*) { return 0; };
//Record lookup(Phone* const) { return 0; }; // redeclare
Record lookup(Account&) { return 0; };
Record lookup(const Account&) { return 0; };
Record lookup(Account*) { return 0; };
Record lookup(const Account*) { return 0; };

const string &shorterString(const string &s1, const string &s2) {
    return (s1.size() <= s2.size()) ? s1 : s2;
}

string &shroterString(string &s1, string &s2) {
    auto &r = shorterString(const_cast<const string&>(s1),
                            const_cast<const string&>(s2));
    return const_cast<string&>(r);
}

void print(const char *cp) {
    if (cp)
        while (*cp)
            cout << *cp++;
}

void print(const int *beg, const int *end) {
    while (beg != end) {
        cout << *beg++ << endl;
    }
}

void print(const int ia[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << ia[i] << endl;
    }
}

int main(int argc, char **argv) {
    int j[2] = {0, 1};
    print("Hello World");
    print(j, end(j) - begin(j));
    print(begin(j), end(j));

    Account acct = 0;
    Phone phone = 0;
    Record r1 = lookup(acct);
    Record r2 = lookup(phone);

    
    return 0;
}
