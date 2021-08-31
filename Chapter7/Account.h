#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

typedef double Money;
std::string bal;

class Account {
public:
    Money balance() { return bal; }
private:
    typedef double Money;   // error, compiler accepts it
    Money bal = 30.2;;
};


#endif