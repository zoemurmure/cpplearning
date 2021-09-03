#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

bool find(vector<int>::const_iterator, vector<int>::const_iterator, const int);

int main() {
    vector<int> a{2,6,54,33,65,2,90};
    int val;
    while (cin >> val) {
        cout << find(a.begin(), a.end(), val) << endl;
    }
    
    return 0;
}

bool find(vector<int>::const_iterator b, 
          vector<int>::const_iterator e, const int n) {
    while (b != e) {
        if (*b == n) return true;
        ++b;
    }
    return false;
}
