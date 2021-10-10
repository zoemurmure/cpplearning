#include "Limit_quote.h"
#include <iostream>
using namespace std;

double Limit_quote::net_price(size_t n) const {
    if (n > max_qty) {
        return max_qty * (1 - discount) * price + (n - max_qty) * price;
    } else {
        return n * (1 - discount) * price;
    }
}