#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item curr, next;

    int cnt = 1;
    std::cin >> curr;

    while (std::cin >> next) {
        if (next.isbn() == curr.isbn()) {
            cnt++;
        } else {
            std::cout << curr << "  Count: " << cnt << std::endl;
            cnt = 1;
            curr = next;
        }
    }

    return 0;
} 
