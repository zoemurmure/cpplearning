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
    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    cout << bp1->fcn() << endl;
    cout << bp2->fcn() << endl;
    cout << bp3->fcn() << endl;
    
    D1 *d1p = &d1obj; D2 *d2p = &d2obj;
    //bp2->f2(); //error: 'struct Base' has no member named 'f2'
    d1p->f2();
    d2p->f2();

    Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
    //p1->fcn(42); // error
    cout << p2->fcn(42) << endl;
    cout << p3->fcn(42) << endl;
    return 0;
}