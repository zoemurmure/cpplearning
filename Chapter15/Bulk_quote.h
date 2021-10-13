#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
//#include "Quote.h"
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    //Bulk_quote(const std::string &book, double price,
    //         std::size_t qty, double disc) :
    //         Disc_quote(book, price, qty, disc) { }
    using Disc_quote::Disc_quote;
    double net_price(std::size_t) const override;
    std::ostream &debug(std::ostream &os) const override {
        Quote::debug(os) << " Bulk_quote::quantity " << quantity
            << " Bulk_quote::discount " << discount;
        return os;
    }
//private:
//    std::size_t min_qty = 0;
//    double discount = 0.0;    
};


#endif