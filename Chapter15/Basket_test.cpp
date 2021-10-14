#include "Basket.h"
using namespace std;

/*
    vector<shared_ptr<Quote>> basket2;
    basket2.push_back(make_shared<Bulk_quote>("1-1-1", 50, 20, 0.35));
    basket2.push_back(make_shared<Bulk_quote>("1-1-1", 50, 10, 0.25));
    basket2.push_back(make_shared<Bulk_quote>("1-1-1", 50, 5, 0.75));
*/

int main() {
    Basket b;
    for (size_t i = 0; i < 20; i++)
        b.add_item(Quote("123", 50));
    for (size_t i = 0; i < 20; i++)
        b.add_item(Bulk_quote("234", 50, 10, 0.25));
    for (size_t i = 0; i < 20; i++)
        b.add_item(Limit_quote("345", 50, 10, 0.75));

    b.total_receipt(cout);
    return 0;
}