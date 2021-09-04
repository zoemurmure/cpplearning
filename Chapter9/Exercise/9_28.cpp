#include <forward_list>
#include <string>
#include <iostream>
using std::forward_list; using std::string;
using std::cin; using std::cout; using std::endl;

void find_insert(forward_list<string>& flst, 
                const string &w1, const string &w2) {
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr == w1) {
            flst.insert_after(prev, w2);
            return;
        } else {
            prev = curr;
            ++curr;
        }
    }
    flst.insert_after(prev, w2);
    return;
}

int main() {
    forward_list<string> sentence{"Tom", "is", "a", "cat"};
    string word1, word2;
    cin >> word1 >> word2;
    find_insert(sentence, word1, word2);
    for (auto s : sentence) {
        cout << s << " ";
    }
    return 0;
}