#ifndef FOO_H
#define FOO_H
#include <vector>
#include <algorithm>
#include <iostream>

class Foo {
    friend void print(const Foo&);
public:
    Foo(): data(std::vector<int>()) { }
    Foo(std::vector<int> a): data(a) { }
    Foo(const Foo &f): data(f.data) { }
    Foo sorted() &&;
    Foo sorted() const &;

    std::vector<int>::const_iterator begin() const  { return data.begin(); }
    std::vector<int>::const_iterator end() const { return data.end(); }

private:
    std::vector<int> data;
};

void print(Foo &f) {
    for (auto t = f.begin(); t != f.end(); ++t) {
        std::cout << *t << " ";
    }
}

Foo Foo::sorted() && {
    std::cout << "sorted() &&" << std::endl;
    sort(data.begin(), data.end());
    return *this;
}

// version 1
//Foo Foo::sorted() const & {
//    std::cout << "sorted() const &" << std::endl;
//    Foo ret(*this);
//    sort(ret.data.begin(), ret.data.end());
//    return ret;
//}

// version 13.56
// 无限循环
//Foo Foo::sorted() const & {
//    std::cout << "sorted() const &" << std::endl;
//    Foo ret(*this);
//    return ret.sorted();
//}

// version 13.57
// OK
Foo Foo::sorted() const & {
    std::cout << "sorted() const &" << std::endl;
    return Foo(*this).sorted();
}

#endif