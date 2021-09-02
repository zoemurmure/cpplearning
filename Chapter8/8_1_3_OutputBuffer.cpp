#include <iostream>
using namespace std;

int main() {
    // flushing
    cout << "hi!" << endl;
    cout << "hi!" << flush;
    cout << "hi!" << ends;
    cout << "test" << endl;
    // unitbuf
    //cout << unitbuf;
    //cout << nounitbuf;
    // crash & flushing
    //cout << "test crash case";
    //int i = 5/0;

    // tie
    //cin.tie(&cout);
    ostream *old_tie = cin.tie(nullptr);
    cin.tie(&cerr);
    cout << "test tie";
    string s;
    cin >> s;
    cout << s;
    return 0;
}