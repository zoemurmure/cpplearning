#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector<unsigned> scores(11, 0);
    unsigned grade;
    auto it = scores.begin();

    while (cin >> grade) {
        if (grade <= 100) {
            *(it+grade/10) += 1;
        }
    }
    for (; it != scores.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
