#ifndef SMALLINT_H
#define SMALLINT_H

class SmallInt {
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
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

SmallInt operator+(const SmallInt &a, const SmallInt &b) {
    return static_cast<int>(a) + static_cast<int>(b);
}




#endif