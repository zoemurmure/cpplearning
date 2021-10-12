#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include <string>
#include "Quote.h"

class Disc_quote : public Quote {
public:
    Disc_quote(): Quote() {
        std::cout << "Disc_quote" << std::endl;
    }
    ~Disc_quote() {
        std::cout << "~Disc_quote()" << std::endl;
    }
    Disc_quote(const Disc_quote &dq): 
        Quote(dq), quantity(dq.quantity), discount(dq.discount) {
        std::cout << "Disc_quote(const Disc_quote&)" << std::endl;
    }
    Disc_quote(Disc_quote &&dq): 
        Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount)) {
        std::cout << "Disc_quote(Disc_quote&&)" << std::endl;
    }
    Disc_quote& operator=(const Disc_quote &rhs) {
        Quote::operator=(rhs);
        std::cout << "operator=(const Disc_quote&)" << std::endl;
        quantity = rhs.quantity;
        discount = rhs.discount;
        return *this;
    }
    Disc_quote& operator=(Disc_quote &&rhs) {
        Quote::operator=(std::move(rhs));
        std::cout << "operator=(Disc_quote&&)" << std::endl;
        quantity = std::move(rhs.quantity);
        discount = std::move(rhs.discount);
        return *this;
    }
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