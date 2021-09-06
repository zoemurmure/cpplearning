#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>

using namespace std;

bool isOdd(int num) {
    return num % 2;
}

int main() {
    string fileName{"1033text"}, odd("odd"), even("even");
    ifstream in(fileName);
    ofstream out_odd(odd), out_even(even);
    istream_iterator<int> in_iter(in), eof;
    ostream_iterator<int> odd_iter(out_odd, " "), even_iter(out_even, "\n");
    vector<int> nums(in_iter, eof);
    auto odd_end = partition(nums.begin(), nums.end(), isOdd);
    copy(nums.begin(), odd_end, odd_iter);
    copy(odd_end, nums.end(), even_iter);
    return 0;
}