#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
    friend std::istream &read(std::istream&, Person&);
    friend std::ostream &print(std::ostream&, const Person&);
public:
    Person() = default;
    Person(const std::string &n, const std::string &a):
        name(n), address(a) { }
    Person(const std::string &n): name(n) { }

    std::string getName() const { return name; }
    std::string getAddr() const { return address; }
private:
    std::string name = "";
    std::string address = "";
};

std::istream &read(std::istream &, Person &);
std::ostream &print(std::ostream &, const Person &);
#endif