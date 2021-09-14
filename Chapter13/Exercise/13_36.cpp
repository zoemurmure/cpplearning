#include "Message.h"
#include "Folder.h"
#include <iostream>
using namespace std;
int main() {
    Folder f1, f2;
    Message m1("Hello"), m2("World"), m3("Happy"), m4("New Year"), m5(":-)");
    m1.save(f1);
    m2.save(f2);
    return 0;
}