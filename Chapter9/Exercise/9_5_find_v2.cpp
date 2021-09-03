#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

vector<int>::const_iterator
find(vector<int>::const_iterator, vector<int>::const_iterator, const int);

int main() {
    vector<int> a{2,6,54,33,65,2,90};
    int val;
    while (cin >> val) {
        auto t = find(a.begin(), a.end(), val);
        if (t != a.end())
            cout << "Find element " << *t << endl;
        else
            cout << "Not find element " << val << endl;
    }
    
    return 0;
}

vector<int>::const_iterator
find(vector<int>::const_iterator b, 
          vector<int>::const_iterator e, const int n) {
    while (b != e) {
        if (*b == n) return b;
        ++b;
    }
    return b;
}
