#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    istream_iterator<int> in_iter(cin), eof;
    ostream_iterator<int> out_iter(cout, " ");

    vector<int> vec(in_iter, eof);
    sort(vec.begin(), vec.end());
    unique_copy(vec.cbegin(), vec.cend(), out_iter);

    return 0;
}