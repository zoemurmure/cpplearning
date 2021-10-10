#include <string>
#include "Quote.h"

class Limit_quote : public Quote {
public:
    Limit_quote() = default;
    Limit_quote(const std::string &book, double p,
                std::size_t qty, double disc) :
                Quote(book, p), max_qty(qty), discount(disc) { }
    double net_price(std::size_t n) const override;
    std::ostream &debug(std::ostream &os) const override {
        Quote::debug(os) << " Limit_quote::max_qty " << max_qty
            << " Limit_quoteL::discount " << discount;
        return os;
    }
private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};