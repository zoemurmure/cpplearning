#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
#include "Sales_data.h"
using namespace std;

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {
    return sd1.isbn() < sd2.isbn();
}

int main() {
    string fileName{"1012text"};
    ifstream in(fileName);
    vector<Sales_data> sd;
    Sales_data data;
    while (read(in, data)) {
        sd.push_back(data);
    }

    sort(sd.begin(), sd.end(), compareIsbn);
    for (auto i : sd) {
        print(cout, i) << endl;
    }
    return 0;
}