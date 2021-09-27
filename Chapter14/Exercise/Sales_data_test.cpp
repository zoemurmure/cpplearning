#include "Sales_data.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream in("book_sales");
    vector<Sales_data> vsd;
    Sales_data sd;
    while (in >> sd) {
        vsd.push_back(sd);
        cout << sd << endl;
    }

    return 0;
}