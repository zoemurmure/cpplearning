#include <list>
#include <string>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>
using std::list; using std::string;
using std::vector; using std::deque;
using std::forward_list; using std::array;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
    list<string> authors = {"Milton", "Shakespeare", "Austen"};
    vector<const char*> articles = {"a", "an", "the"};
    list<string> list2(authors);
    forward_list<string> words(articles.begin(), articles.end());
    
    array<int, 3> a{1,2,3};
    return 0;
}