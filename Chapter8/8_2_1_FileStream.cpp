#include <iostream>
using std::cout; using std::cin; using std::endl; using std::cerr;
#include <fstream>
using std::ifstream; using std::ofstream;
#include <string>
using std::string;
#include "Sales_data.h"

int main(int argc, char** argv) {
    ifstream input(argv[1]);
    ofstream output(argv[2]);

    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }
    return 0;
}