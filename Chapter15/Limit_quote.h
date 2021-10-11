#include <string>
#include "Disc_quote.h"

class Limit_quote : public Disc_quote {
public:
    Limit_quote() = default;
    Limit_quote(const std::string &book, double p,
                std::size_t qty, double disc) :
                Disc_quote(book, p, qty, disc) { }
    double net_price(std::size_t n) const override;
    std::ostream &debug(std::ostream &os) const override {
        Quote::debug(os) << " Limit_quote::quantity " << quantity
            << " Limit_quoteL::discount " << discount;
        return os;
    }
//private:
//    std::size_t max_qty = 0;
//    double discount = 0.0;
};