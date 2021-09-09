#include <map>
#include <iostream>
#include <set>

using namespace std;

int main() {
    map<string, size_t> word_count{{"first", 1},
                    {"second", 2},
                    {"third", 3}};
    auto map_it = word_count.begin();
    cout << map_it->first;
    cout << " " << map_it->second << endl;
    //map_it->first = "new key";
    ++map_it->second;
    cout << map_it->first << " " << map_it->second << endl;

    set<int> iset = {0,1,2,3,4,5,6,7,8,9};
    set<int>::iterator set_it = iset.begin();
    while (set_it != iset.end()) {
        //*set_it = 42;
        cout << *set_it++ << endl;
    }
    return 0;
}