#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector<unsigned> scores = {34, 55, 60, 76, 86, 100, 91, 23};
    for (const auto grade : scores) {
        cout << grade << " ";
        if (grade > 90) {
            cout << "high pass";
        } else if (grade > 75) {
            cout << "pass";
        } else if (grade >= 60) {
            cout << "low pass";
        } else {
            cout << "fail";
        }
        cout << endl;
    }
    return 0;
}
