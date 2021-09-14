#ifndef HASPTR_H
#define HASPTR_H
#include <iostream>
class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp):
        ps(new std::string(*(hp.ps))), i(hp.i) { }
    //HasPtr& operator= (const HasPtr&);
    HasPtr& operator= (HasPtr);
    bool operator< (const HasPtr&);
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "Before swap: " << *lhs.ps 
            << " " << *rhs.ps << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "After swap: " << *lhs.ps 
            << " " << *rhs.ps << std::endl;
}

//HasPtr& HasPtr::operator= (const HasPtr &rhs) {
//    auto temp = new std::string(*(rhs.ps));
//    delete ps;
//    ps = temp;
//    i = rhs.i;
//    return *this;
//
//}

HasPtr& HasPtr::operator= (HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}

bool HasPtr::operator< (const HasPtr &rhs) {
    return *(this->ps) < *(rhs.ps);
}


#endif