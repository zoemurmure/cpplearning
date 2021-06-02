#include <iostream>
int main() {
    int a = 0, b = 0;
    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> a >> b;
    std::cout << "The sum of " << a << " and " << b 
            << " is " << a * b << std::endl;
    return 0;
}
