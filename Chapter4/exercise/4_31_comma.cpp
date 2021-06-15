#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector<int> ivec(10);
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt) {
        ivec[ix] = cnt;
        cout << ivec[ix] << " ";
    }
    cout << endl;
    
    vector<int> jvec(10);
    cnt = jvec.size(); 
    for (vector<int>::size_type ix = 0; ix != jvec.size(); ix++, cnt--) {
        jvec[ix] = cnt;
        cout << jvec[ix] << " ";
    }
    return 0;
}
