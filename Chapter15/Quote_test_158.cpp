#include <iostream>
#include <vector>
#include <memory>
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
    vector<Quote> basket1;
    basket1.push_back(Bulk_quote("1-1-1", 50, 20, 0.35));
    basket1.push_back(Bulk_quote("1-1-1", 50, 10, 0.25));
    basket1.push_back(Bulk_quote("1-1-1", 50, 5, 0.75));

    for (const auto &q : basket1) {
        print_total(cout, q, 30);
    }

    vector<shared_ptr<Quote>> basket2;
    basket2.push_back(make_shared<Bulk_quote>("1-1-1", 50, 20, 0.35));
    basket2.push_back(make_shared<Bulk_quote>("1-1-1", 50, 10, 0.25));
    basket2.push_back(make_shared<Bulk_quote>("1-1-1", 50, 5, 0.75));
    
    for (const auto q : basket2) {
        print_total(cout, *q, 30);
    }

    return 0;
}