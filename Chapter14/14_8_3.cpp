#include <iostream>
#include <functional>
#include <map>
#include <string>
using namespace std;

int add(int i, int j) { return i + j; }

double add(double i, double j) { return i + j; }

auto mod = [](int i, int j) { return i % j; };

struct divide {
    int operator()(int i, int j) {
        return i / j;
    }
};

int main() {
    //function<int(int, int)> f1 = add;
    //function<int(int, int)> f2 = divide();
    //function<int(int, int)> f3 = mod;
//
    //cout << f1(4, 2) << endl;
    //cout << f2(4, 2) << endl;
    //cout << f3(4, 2) << endl;

    //map<string, int(*)(int, int)> binops;
    //binops.insert({"+", add});
    //binops.insert({"%", divide()});  // error
    //cout << binops["%"](4, 2) << endl;

    int (*fp)(int, int) = add;

    map<string, function<int(int, int)>> binops = {
        {"+", fp},
        {"-", minus<int>()},
        {"/", divide()},
        {"*", [](int i, int j) { return i * j; }},
        {"%", mod}
    };
    cout << binops["+"](10, 5) << endl;
    cout << binops["-"](10, 5) << endl;
    cout << binops["/"](10, 5) << endl;
    cout << binops["*"](10, 5) << endl;
    cout << binops["%"](10, 5) << endl;

    return 0;
}