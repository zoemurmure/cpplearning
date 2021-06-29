#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Sales_item.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::runtime_error
int main() {
    Sales_item item1, item2;
    while (cin >> item1 >> item2) {
        try {
            if (item1.isbn() != item2.isbn()) 
                throw runtime_error("Data must refer to same ISBN");
            cout << item1 + item2 << endl;
        } catch (runtime_error err) {
            cout << err.what()
                 << "\nTry again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
    return 0;
}
