#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    int nums[10];
    for (unsigned i = 0; i < 10; ++i) {
        nums[i] = i;
        cout << nums[i] << " " ;
    }
    cout << endl;
    return 0;
}
