#include <memory>
#include <iostream>
#include <string>
using namespace std;

unique_ptr<int> clone(int p) {
    return unique_ptr<int>(new int(p));
}

int main() {
    unique_ptr<string> p1(new string("Stegosaurus"));
    //unique_ptr<string> p2(p1);   // error
    unique_ptr<string> p2(p1.release());
    unique_ptr<string> p3(new string("Trex"));
    p2.reset(p3.release());

    // remember to delete
    auto p = p2.release();
    delete p;

    return 0;
}