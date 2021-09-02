#include <iostream>
using std::cout; using std::cin; using std::endl; using std::cerr;
#include <fstream>
using std::ifstream; using std::ofstream;
#include <string>
using std::string;

int main() {
    ofstream out("test.txt", ofstream::app);
    out.close();
    return 0;
}