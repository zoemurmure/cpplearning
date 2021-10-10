#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
using namespace std;

double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main() {
    Quote basic("1-1-1", 12.5);
    Bulk_quote bulk("1-1-1", 12.5, 10, 0.7);
    Limit_quote lq("1-1-1", 12.5, 10, 0.7);
    print_total(cout, basic, 20);
    print_total(cout, bulk, 20);  
    print_total(cout, lq, 20);   
    basic.debug(cout) << endl;
    bulk.debug(cout) << endl;
    lq.debug(cout) << endl;
    //Quote item;
    //Bulk_quote bulk;
    //Quote *p = &item;
    //p = &bulk;
    //Quote &r = bulk;

    return 0;
}