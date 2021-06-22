#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector<int> num1{0, 1, 1, 2};
    vector<int> num2{0, 1, 1, 2, 3, 5, 8};
    bool isPrefix = true;

    for (decltype(num1.size()) i = 0; i < num1.size() && i < num2.size(); ++i) {
        if (num1[i] != num2[i]) {
            isPrefix = false;
            break;
        } 
    }
    cout << isPrefix << endl;

    return 0;
}
