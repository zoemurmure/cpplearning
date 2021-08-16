#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    string result = "";
    for (auto i = 1; i < argc; ++i) {
        result += argv[i];
    }
    cout << result << endl;
    return 0;
}
