#include <iostream>

int main() {
    int a = 0, b = 0;
    std::cout << "Please input two numbers: " << std::endl;
    std::cin >> a >> b;
    while (a > b) {
        std::cout << a << " ";
        --a;
    }
    while (a <= b) {
        std::cout << a << " ";
        ++a;
    }

    return 0;
}
