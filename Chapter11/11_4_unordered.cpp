#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

size_t hasher(const Sales_data &sd) {
    return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
}

using SD_multiset = unordered_multiset<Sales_data, 
                decltype(hasher)*, decltype(eqOp)*>;

int main() {
    //unordered_map<string, size_t> word_count;
    //string word;
    //while (cin >> word) {
    //    ++word_count[word];
    //}
//
    //for (const auto &w : word_count) {
    //    cout << w.first << " " << w.second << endl;
    //}
    SD_multiset bookstore(42, hasher, eqOp);

    return 0;
}