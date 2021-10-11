#include <iostream>
using namespace std;

struct Base {
    Base() : mem(0) { }
    int memfcn() { return 0; }
    virtual int fcn() { return 0; }
protected:
    int mem;
};

struct Derived : Base {
    Derived() = default;
    Derived(int i): mem(i) { }
    int get_mem() { return mem; }
    int memfcn(int i) { return i; }
protected:
    int mem;
};

struct D1 : public Base {
    int fcn(int i) { return i; }
    virtual void f2() { }
};

struct D2 : public D1 {
    int fcn(int i) { return i + 1; }
    int fcn() { return 1; }
    void f2() { }
};

int main() {
    //Derived d(42);
    //cout << d.get_mem() << endl;
    //Derived d; Base b;
    //b.memfcn();
    //d.memfcn(10);
    //d.memfcn(); // error
    //d.Base::memfcn();

    Base bobj; D1 d1obj; D2 d2obj;
    
    return 0;
}