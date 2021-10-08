#ifndef QUOTE_H
#define QUOTE_H
#include <string>
class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
            bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const {
        return n * sales_price;
    }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};



#endif