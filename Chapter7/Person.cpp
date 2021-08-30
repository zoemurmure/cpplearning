#include <iostream>
using std::istream;
using std::ostream;

#include "Person.h"

istream &read(istream &is, Person &p) {
    is >> p.name >> p.address;
    return is;
}

ostream &print(ostream &os, const Person &p) {
    os << p.name << " " << p.address;
    return os;
}