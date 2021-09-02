#include <iostream>
#include <string>
using namespace std;

istream& print(istream& is) {
    string s;
    while (is >> s) {
        cout << s << endl;
    }
    cout << "State of cin: " << cin.rdstate() << endl;
    is.clear();
    return is;
}

int main() {
    print(cin);
    cout << "State of cin: " << cin.rdstate() << endl;
    return 0;
}