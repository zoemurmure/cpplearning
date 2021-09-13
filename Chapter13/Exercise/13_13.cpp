#include <iostream>
#include <vector>
struct X {
    X() {
        std::cout << "X()" << std::endl;
    }
    X(const X&) {
        std::cout << "X(const X&)" << std::endl;
    }
    X& operator= (const X &) {
        std::cout << "operator=" << std::endl;
        return *this;
    }
    ~X() {
        std::cout << "~X()" << std::endl;
    }
};

X test1(X a) {
    return a;
}

X test2(X &a) {
    return a;
}

int main() {
    X a;
    //X b(a);
    //X c = a;
    //test1(a);
    //test2(a);
    std::vector<X> d{a};
    //d.push_back(a);
    return 0;
}