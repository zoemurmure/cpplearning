#ifndef READSTRING_H
#define READSTRING_H
#include <iostream>
#include <string>

class ReadString {
public:
    ReadString(): s("") { }
    std::string& operator()(std::istream &is) {
        std::getline(is, s);
        return s;
    }
private:
    std::string s;
};


#endif