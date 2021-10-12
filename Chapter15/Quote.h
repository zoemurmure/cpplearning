#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>
class Quote {
public:
    Quote(): bookNo("") {
        std::cout << "Quote()" << std::endl;
    }
    Quote(const Quote &q): bookNo(q.bookNo), price(q.price) {
        std::cout << "Quote(const Quote&)" << std::endl;
    }
    Quote(Quote &&q): bookNo(std::move(q.bookNo)),
            price(std::move(q.price)) {
        std::cout << "Quote(Quote&&)" << std::endl;
    }
    Quote& operator=(const Quote &rhs) {
        std::cout << "operator=(const Quote&)" << std::endl;
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }
    Quote& operator=(Quote &&rhs) {
        std::cout << "operator=(const Quote&&)" << std::endl;
        bookNo = std::move(rhs.bookNo);
        price = std::move(rhs.price);
        return *this;
    }
    Quote(const std::string &book, double sales_price):
            bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const {
        return n * price;
    }
    virtual std::ostream &debug(std::ostream &os) const {
        os << "Quote::bookNo " << bookNo << " Quote::price " << price;
        return os;
    }
    virtual ~Quote() {
        std::cout << "~Quote()" << std::endl;
    }
private:
    std::string bookNo;
protected:
    double price = 0.0;
};



#endif