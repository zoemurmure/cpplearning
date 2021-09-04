#include <stack>
#include <vector>
#include <deque>
using std::stack;
using std::vector;
using std::deque;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
    stack<int> intStack;
    for (size_t ix = 0; ix != 10; ++ix) {
        intStack.push(ix);
    }
    while (!intStack.empty()) {
        int value = intStack.top();
        intStack.pop();
        cout << value << endl;
    }

    return 0;
}