#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

//double Account::initRate() {
//    cout << period << endl;
//    return 0.25;
//}

double Account::interestRate = initRate();

//void Account::rate(double r) {
//    interestRate = r;
//}


int main() {
    double r;
    r = Account::rate();

    Account ac1;
    Account *ac2 = &ac1;

    r = ac1.rate();
    r = ac2->rate();
}