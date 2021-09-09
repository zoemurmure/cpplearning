#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    multimap<string, string> authors = 
    {{"Alain", "fake"}, {"Bob", "nerd"},
     {"Zoe", "ball"}, {"Bob", "test"}};
    string search_item;

    while (cin >> search_item) {
        auto item = authors.find(search_item);
        while (item->first == search_item) {
            authors.erase(item);
            item = authors.find(search_item);
        }

        for (const auto &i : authors)
            cout << i.first << " " << i.second << endl;
    }
    return 0;
}