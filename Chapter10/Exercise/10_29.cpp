#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string fileName{"1029text"};
    ifstream in(fileName);
    istream_iterator<string> in_iter(in), eof;
    vector<string> words(in_iter, eof);

    for (const auto &i : words) {
        cout << i << " ";
    }
    return 0;
}