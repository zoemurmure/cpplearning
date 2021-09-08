#include <utility>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<pair<string, int>> data;
    pair<string, int> temp;
    while (cin >> temp.first >> temp.second) {
        data.push_back(temp);
    }

    for (const auto &t : data) {
        cout << t.first << " " << t.second << endl;
    }
    return 0;
}