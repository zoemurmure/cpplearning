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
        cout << grade << " " <<
            ((grade > 90) ? "high pass" :
            ((grade > 75) ? "pass" :
            ((grade >= 60) ? "low pass" : "fail"))) << endl;
    }
    return 0;
}
