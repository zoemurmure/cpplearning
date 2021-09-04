#include <string>
#include <iostream>
using std::string;
using std::cin; using std::cout; using std::endl;

int main() {
    //string name("AnnaBelle");
    //auto pos1 = name.find("Anna");
    //cout << pos1 << endl;

    string numbers("0123456789"), name("r2d2");
    //auto pos = name.find_first_of(numbers);
    //cout << pos << endl;
//
    //string dept("03432ds8");
    //pos = dept.find_first_not_of(numbers);
    //cout << pos << endl;

    string::size_type pos = 0;
    while ((pos = name.find_first_of(numbers, pos)) != string::npos) {
        cout << "found number at index: " << pos 
            << " element is " << name[pos] << endl;
        ++pos;
    }

    string river("Mississippi");
    auto first_pos = river.find("is");
    auto last_pos = river.rfind("is");
    cout << first_pos << " " << last_pos << endl;
    return 0;
}