#include <string>
#include <iostream>
#include <fstream>
using std::string;
using std::cin; using std::cout; using std::endl;
using std::ifstream; using std::ofstream;

const string SPECIAL{"bdfghjklpqty"};

bool hasSpecial(const string &s) {
    if (s.find_first_of(SPECIAL) != string::npos) return true;
    else return false;
}

int main() {
    string fileName = "949text";
    ifstream in(fileName);

    string word;
    string max = "";
    while (in >> word) {
        if (!hasSpecial(word)) 
            max = word.size() > max.size() ? word : max;
    }
    cout << max << endl;
    return 0;
}