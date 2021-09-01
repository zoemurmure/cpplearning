#include <iostream>
#include <string>
#include <vector>
using std::istream;
using std::ostream;
using std::string;
using std::vector;

#include "Sales_data.h"

//Sales_data::Sales_data(std::istream &is) {
//    read(is, *this);
//}


Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main() {
    Sales_data sd;
    std::cout << sd.isbn() << std::endl;

    Sales_data item("9-999-99999-9");
    string null_book = "9-999-99999-9";

    Sales_data item1(null_book);
    //Sales_data item2 = null_book;
    //item.combine(null_book);
    //item.combine(std::cin);
    item.combine(Sales_data(null_book));
    //item.combine(static_cast<Sales_data>(std::cin));
    print(std::cout, item);


    return 0;
}