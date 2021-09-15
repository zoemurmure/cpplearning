#include <iostream>
#include <utility>
using namespace std;

int main() {
    int i = 42;
    int &r = i;
    int &&rr3 = std::move(r);
    return 0;
}