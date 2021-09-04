#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <string>

using std::list; using std::string;
using std::vector; using std::deque;
using std::forward_list; using std::array;
#include <iostream>
using std::cin; using std::cout; using std::endl;

void pluralize(size_t cnt, string &word) {
    if (cnt > 1) {
        word.push_back('s');
    }
}

int main() { 
    // push_back
    vector<string> container;
    string word;
    //while (cin >> word) {
    //    container.push_back(word);
    //}

    // push_front
    list<int> ilist;
    for (size_t ix = 0; ix != 4; ++ix) {
        ilist.push_front(ix);
    }

    // insert
    vector<string> svec;
    list<string> slist;
    slist.insert(slist.begin(), "Hello!");
    svec.insert(svec.begin(), "Hello!");

    svec.insert(svec.end(), 10, "Anna");

    vector<string> v = {"quasi", "simba", "frollo", "scar"};

    slist.insert(slist.begin(), v.end()-2, v.end());
    slist.insert(slist.end(), {"these", "words", "will",
                                "go", "at", "the", "end"});
    // 这句竟然没出错？！
    slist.insert(slist.begin(), slist.begin(), slist.end());

    for (auto t : svec) {
        cout << t << " ";
    }
    cout << endl;

    for (auto t : slist) {
        cout << t << " ";
    }
    cout << endl;

    list<string> lst;
    auto iter = lst.begin();
    while (cin >> word) {
        iter = lst.insert(iter, word);
    }

    return 0;
}