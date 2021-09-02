#include <iostream>
using namespace std;

/*
strm::iostate

strm::badbit
strm::failbit
strm::eofbit
strm::goodbit

s.eof()
s.fail()
s.bad()
s.good()

s.clear()
s.clear(flags) ->     s = flags
s.setstate(flags) ->  s += flags

s.rdstate()
*/
void process_input(istream& in) {
    int i;
    in >> i;
    cout << in.rdstate() << endl;
    in.clear(in.rdstate() & ~istream::failbit & ~istream::badbit);
    cout << in.rdstate() << endl;
} 

int main() {
    auto old_state = cin.rdstate();
    cin.clear();
    process_input(cin);
    cin.setstate(old_state);
}