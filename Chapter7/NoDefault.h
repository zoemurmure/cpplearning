#ifndef NODEFAULT_H
#define NODEFAULT_H
#include <string>
#include <vector>

class NoDefault {
public:
    //NoDefault() = default;
    NoDefault(const std::string&) { }
    NoDefault(int i): n(i) { }
private:
    int n = 0;
};

struct C {
    C(): nd(1) { }
    NoDefault nd;
};

//struct A {
//    NoDefault my_mem;
//};
//
//A a;
//
//struct B {
//    B() { }
//    NoDefault b_member;
//};

#endif