#include <list>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    list<string> words{"rad", "the", "quick", "rad", "fox", "jumps", "over", "the", "slow", "rad", "turtle", "rad", "the"};
    words.sort();
    words.unique();
    for (const auto &s : words) 
        cout << s << " ";
    return 0;
}