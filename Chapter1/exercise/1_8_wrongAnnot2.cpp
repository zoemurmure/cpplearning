#include <iostream>

int main() {
    std::cout << "/*";  // Correct！
    std::cout << "*/";  // Correct!
    // std::cout << /* "*/" */; // Wrong!
    std::cout << /* "*/" */"; //
    std::cout << /* "*/" /* "/*" */; // Correct!
}
