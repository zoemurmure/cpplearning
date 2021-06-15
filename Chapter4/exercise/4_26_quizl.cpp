#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    unsigned int quizl = 0;
    unsigned long lUL = 1;

    quizl |= lUL << 27;
    cout << quizl << endl;

    quizl &= ~(lUL << 27);
    cout << quizl << endl;

    bool status = quizl & (lUL << 27);
    cout << status << endl;
    return 0;
}
