#ifndef EXERCISE_H
#define EXERCISE_H
#include <string>

typedef std::string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal() { return 3.2; };
private:
    int val;
};

Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}


#endif