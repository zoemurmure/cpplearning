#include <sstream>
using std::istringstream; using std::ostringstream;
#include <fstream>
using std::ifstream; using std::ofstream;
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(const string &s) {
    return true;
}

string format(const string &s) {
    return s;
}

int main() {
    string fileName = "data/sstream";
    ifstream in(fileName);
    ofstream out("outputNums");

    string line, word;
    vector<PersonInfo> people;

    while (getline(in, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for (const auto &entry : people) {
        ostringstream formatted, badNums;
        for (const auto &num : entry.phones) {
            if (!valid(num)) {
                badNums << " " << num;
            } else {
                formatted << " " << format(num);
            }
        }
        if (badNums.str().empty()) {
            out << entry.name << " "
                << formatted.str() << endl;
        } else {
            out << "input error: " << entry.name
                << " invalid number(s) " << badNums.str() << endl;
        }
    }
    return 0;
}