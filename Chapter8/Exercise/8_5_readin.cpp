#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <fstream>
using std::ifstream; using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    if (!in) return -1;
    vector<string> contents;
    string s;
    while (in >> s) {
        contents.push_back(s);
    }

    for (string s : contents) {
        cout << s << endl;
    }

    return 0;
}