#include <string>
#include <vector>
#include <iostream>
using std::string; using std::vector;
using std::cin; using std::cout; using std::endl;

int sumOfIntString(const vector<string> &s) {
    int sum = 0;
    for (auto t : s) {
        sum += std::stoi(t);
    }
    return sum;
}

double sumOfDoubleString(const vector<string> &s) {
    double sum = 0.0;
    for (auto t : s) {
        sum += std::stod(t);
    }
    return sum;
}

int main() {
    vector<string> numbers;
    string num;
    while (cin >> num) {
        numbers.push_back(num);
    }

    cout << sumOfIntString(numbers) << endl;
    return 0;
}