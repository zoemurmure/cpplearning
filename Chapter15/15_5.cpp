#include <iostream>
using namespace std;
class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

class Sneaky : public Base {
    friend void clobber(Sneaky&);
    friend void clobber(Base&);
    int j;
    // Exercise 15.19
    void memfcn(Base &b) { b = *this;}
};

void clobber(Sneaky &s) {
    s.j = s.prot_mem = 0;
}

void clobber(Base &b) {
    //b.prot_mem = 0; // error
}

struct Pub_Derv : public Base {
    int f() { return prot_mem; }
    //char g() { return priv_mem; } // error
    // Exercise 15.19
    void memfcn(Base &b) { b = *this;}
};

struct Priv_Derv : private Base {
    int f1() const { return prot_mem; }
    // Exercise 15.19
    void memfcn(Base &b) { b = *this;}
};

struct Prot_Derv : protected Base {
    int f2() const { return prot_mem; }
    // Exercise 15.19
    void memfcn(Base &b) { b = *this;}
};

struct Derived_from_Public : public Pub_Derv {
    int use_base() { return prot_mem; }
    // Exercise 15.19
    void memfcn(Base &b) { b = *this;}
};

struct Derived_from_Private : public Priv_Derv {
    //int use_base() { return prot_mem; } // error
    // Exercise 15.19
    //void memfcn(Base &b) { b = *this;} // error
};

struct Derived_from_Protected : public Prot_Derv {
    int use_base() { return prot_mem; }
    // Exercise 15.19
    void memfcn(Base &b) { b = *this;}
};

int main() {
    /*
    // Exercise 15.18
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    Base *p = &d1;
    //p = &d2; // error: 'Base' is an inaccessible base of 'Derived_from_Private'
    //p = &d3;
    p = &dd1;
    //p = &dd2;
    //p = &dd3;
    */


    return 0;
}