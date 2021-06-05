#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item sum, cur;
    std::cin >> sum;
    while (std::cin >> cur) {
        sum += cur;
    }

    std::cout << sum << std::endl;
    return 0;
}
