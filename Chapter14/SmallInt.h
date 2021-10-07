#ifndef SMALLINT_H
#define SMALLINT_H

class SmallInt {
public:
    SmallInt(int i = 0): val(i) {
        if (i < 0 || i > 255) {
            throw std::out_of_range("Bad SmallInt value");
        }
    }
    operator int() const { return val; }
private:
    std::size_t val;
};




#endif