#include <iostream>
int main() {
    int val = 10;
    std::cout << "Number from 10 to 0:"; 
    while (val >= 0) {
        std::cout << " " << val;
        --val;
    }
    return 0;
}
