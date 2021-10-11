#include "Limit_quote.h"
#include <iostream>
using namespace std;

double Limit_quote::net_price(size_t n) const {
    if (n > quantity) {
        return quantity * (1 - discount) * price + (n - quantity) * price;
    } else {
        return n * (1 - discount) * price;
    }
}