#ifndef CONSTREF_H
#define CONSTREF_H

class ConstRef {
public:
    ConstRef() = default;
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int &ri;
};

//ConstRef::ConstRef(int ii) {
//    i = ii;
//    ci = ii;
//    ri = i;
//}

ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) { }

#endif