#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool lengthCompare(const string &a, const string &b) {
    return a.size() > b.size();
}

string::size_type sumLength(const string &a, const string &b) {
    return a.size() + b.size();
}

string::size_type largerLength(const string &a, const string &b) {
    return (a.size() > b.size() ? a.size() : b.size());
}

// function pointer parameters
typedef bool Func(const string&, const string&);
typedef decltype(lengthCompare) Func2;

typedef bool (*FuncP)(const string&, const string&);
typedef decltype(lengthCompare) *FuncP2;

void useBigger(const string &s1, const string &s2,
        bool pf(const string &, const string &));
void useBigger2(const string &s1, const string &s2,
        bool (*pf)(const string &, const string &));
// function type as parameters automatically turn 
// into pointers
void useBigger3(const string&, const string&, Func);
void useBigger4(const string&, const string&, FuncP2);

// returning a pointer to function
using F = int(int*, int);
using PF = int(*)(int*, int);
PF f1(int);
//F f2(int); // error, can't return a function
F *f3(int);
int (*f4(int))(int *, int);
auto f5(int) -> int (*)(int*, int);

decltype(sumLength) *getFcn(const string &);

int main(int argc, char **argv) {
    bool (*pf)(const string &, const string &);
    
    pf = lengthCompare;
    //pf = &lengthCompare;

    bool b1 = pf("Hello", "goodbye");
    bool b2 = (*pf)("hello", "goodbye");
    bool b3 = lengthCompare("hello", "goodbye");

    cout << b1 << " " << b2 << " " << b3 << endl;


    return 0;
}
