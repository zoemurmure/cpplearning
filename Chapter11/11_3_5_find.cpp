#include <map>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // unordered container can use equal_range!!!
    unordered_multimap<string, string> authors = 
    {{"Alain", "fake"}, {"Bob", "nerd"},
     {"Zoe", "ball"}, {"Bob", "test"}};
    string search_item{"Bob"};
    //auto entries = authors.count(search_item);
    //auto iter = authors.find(search_item);
    //while (entries) {
    //    cout << iter->second << endl;
    //    ++iter;
    //    --entries;
    //}

    //for (auto beg = authors.lower_bound(search_item),
    //          end = authors.upper_bound(search_item);
    //     beg != end; ++beg)
    //    cout << beg->second << endl;

    for (auto pos = authors.equal_range(search_item); 
        pos.first != pos.second; ++pos.first) {
        cout << pos.first->second << endl;
    }
    return 0;
}