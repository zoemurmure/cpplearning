#include <iostream>
#include <string>
struct Employee {
public:
    Employee(): id(++default) { }
    Employee(string &n): name(n), id(++default) { }
    Employee(const Employee& e):
        name(e.name), id(++default) { }
    Employee& operator= (const Employee &e):
        name(e.name), id(++default) { return *this; }
private:
    std::string name;
    int id;
    static int default;
};

int Employee::default = 0;