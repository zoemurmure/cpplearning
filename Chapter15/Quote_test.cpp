#include <iostream>
#include <vector>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
using namespace std;


int main() {
    //Quote basic("1-1-1", 12.5);
    //Bulk_quote bulk("1-1-1", 12.5, 10, 0.7);
    //Bulk_quote *bulkp = &bulk;
    //Quote *itemp = &bulk;
    //bulkp->discount_policy();
    ////itemp->discount_policy(); // error

    //Limit_quote lq("1-1-1", 12.5, 10, 0.7);
    //print_total(cout, basic, 20);
    //print_total(cout, bulk, 20);  
    //print_total(cout, lq, 20);   
    //basic.debug(cout) << endl;
    //bulk.debug(cout) << endl;
    //lq.debug(cout) << endl;
    //Disc_quote test;
    //Quote item;
    //Bulk_quote bulk;
    //Quote *p = &item;
    //p = &bulk;
    //Quote &r = bulk;
    //Quote basic("1-1-1", 12.5);
    //Bulk_quote bulk("1-1-1", 12.5, 10, 0.7);
    //Quote b(bulk);
    vector<Quote> basket;
    basket.push_back(Quote("1-1-1", 50));
    basket.push_back(Bulk_quote("1-1-1", 50, 10, 0.25));
    cout << basket.back().net_price(15) << endl;

    return 0;
}