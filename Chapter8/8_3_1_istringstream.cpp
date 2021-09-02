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

int main() {
    string fileName = "data/sstream";
    ifstream in(fileName);

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
    return 0;
}