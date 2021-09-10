#include <memory>
#include <string>
#include <list>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    shared_ptr<string> p1 = make_shared<string>("");
    shared_ptr<list<int>> p2;

    if (p1 && p1->empty()) {
        *p1 = "hi";
        cout << *p1 << endl;
    }

    shared_ptr<int> p3 = make_shared<int>(42);
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    shared_ptr<int> p5 = make_shared<int>();
    auto p6 = make_shared<vector<string>>();

    string *t = p1.get();
    cout << p1.use_count() << endl;
    
    return 0;
}