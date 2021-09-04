#include <vector>
#include <string>
using std::vector; using std::string;
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <fstream>
using std::ifstream; using std::ofstream;

int main() {
    // test file has 1000 'a'
    string fileName = "test";
    ifstream in(fileName);

    vector<string> svec;
    svec.reserve(1024);
    string word;
    while (in >> word) {
        svec.push_back(word);
    }
    svec.resize(svec.size() + svec.size()/2);
    cout << "size: " << svec.size()
         << " capacity: " << svec.capacity() << endl;
    return 0;
}