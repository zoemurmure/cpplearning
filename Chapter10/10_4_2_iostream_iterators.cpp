#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main() {
    //vector<int> vec;
    //istream_iterator<int> in_iter(cin);
    //istream_iterator<int> eof;
    //while (in_iter != eof) {
    //    vec.push_back(*in_iter++);
    //}
    //istream_iterator<int> in(cin), eof;
    //vector<int> vec(in, eof);
//
    //for ( auto i : vec) 
    //    cout << i << " ";
    //cout << endl;
    //cout << "test" << endl;
    //cout << accumulate(in, eof, 0) << endl;

    vector<int> vec{1,2,3,4,5,6};
    ostream_iterator<int> out_iter(cout, " ");
    //for (auto e : vec)
    //    *out_iter++ = e;
    copy(vec.cbegin(), vec.cend(), out_iter);
    return 0;
}