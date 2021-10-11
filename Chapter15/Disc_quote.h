#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include <string>
#include "Quote.h"

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price,
            std::size_t qty, double disc):
            Quote(book, price), quantity(qty), discount(disc) { }
    std::pair<size_t, double> discount_policy() const {
        return {quantity, discount};
    }
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0;
};



#endif