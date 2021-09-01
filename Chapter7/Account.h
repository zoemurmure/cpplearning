#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double r) { interestRate = r; }
private:
    std::string owner;
    double amount;
    static constexpr int period = 30;
    double daily_tbl[period];
    static double interestRate;
    static double initRate() { return 0.25; }
};


#endif