#include <iostream>
struct numbered {
public:
    numbered(): mysn(++num) { } 
    int mysn;
    static int num;
};

int numbered::num = 0;
void f (numbered s) {
    std::cout << s.mysn << std::endl;
}

int main() {
    numbered a, b=a, c=b;
    f(a);
    f(b);
    f(c);
    return 0;
}