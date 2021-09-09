#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

int main() {
    //vector<int> ivec = {2,4,6,8,2,4,6,8};
    //set<int> set2;
    //set2.insert(ivec.cbegin(), ivec.cend());
    //set2.insert({1,3,5,7,1,3,5,7});
//
    //for (const auto i : set2) 
    //    cout << i << " ";
//
    //string word = "test";
    //map<string, size_t> word_count;
    //word_count.insert({word, 1});
    //word_count.insert(make_pair(word, 1));
    //word_count.insert(pair<string, size_t>(word, 1));
    //word_count.insert(map<string, size_t>::value_type(word, 1));
    //for (const auto i : word_count)
    //    cout << i.first << " " << i.second << endl;
    
    // ret: 
    // pair<map<string, size_t>::iterator, bool>
    //map<string, size_t> word_count;
    //string word;
    //while (cin >> word) {
    //    auto ret = word_count.insert({word, 1});
    //    if (!ret.second) {
    //        ++ret.first->second;
    //    }
    //}
//
    //for (const auto& i : word_count) 
    //    cout << i.first << " " << i.second << endl;
     
    multimap<string, string> authors;
    authors.insert({"Barth John", "Sot-Weed Factor"});
    authors.insert({"Barth John", "Lost in the Funhouse"});
    return 0;
}