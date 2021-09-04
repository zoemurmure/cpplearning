// 假设需要计算的算式的优先级全部由括号标示
// 目前只支持加减乘除
#include <stack>
#include <iostream>
#include <string>
using namespace std;

const string NUMS{"1234567890"};
const string OPRTS("+-*/");

double calculate(double oprd1, char c, double oprd2) {
    switch (c) {
        case '+':
            return oprd1 + oprd2;
        case '-':
            return oprd1 - oprd2;
        case '*':
            return oprd1 * oprd2;
        case '/': 
            if (oprd2 == 0) exit(-1);
            return oprd1 / oprd2;
        default:
            exit(-1);
    }
}

double evaluate(const string& expr) {
    stack<char> oprt;
    stack<double> oprd;
    stack<char> pare;
    for (auto i = 0; i < expr.size(); ++i) {
        string c = expr.substr(i, 1);
        if ((c == "(")) {
            pare.push(c[0]);
        } else if (c.find_first_of(OPRTS) != string::npos) {
            oprt.push(c[0]);
        } else if (c == ")") {
            if (pare.size() == 0 || pare.top() != '(') {
                cout << "Wrong";
                return -1;
            } else {
                pare.pop();
            }
            double oprd2 = oprd.top(); oprd.pop();
            double oprd1 = oprd.top(); oprd.pop();
            oprd.push(calculate(oprd1, oprt.top(), oprd2)); oprt.pop();
        }
        else {
            oprd.push(stod(expr.substr(i)));
            i = expr.find_first_not_of(NUMS, i);
            if (i == string::npos) break;
            else --i;
        }
    }
    if (pare.size() != 0) {
        cout << "Wrong";
        return -1;
    }
    while (oprt.size()) {
        double oprd2 = oprd.top(); oprd.pop();
        double oprd1 = oprd.top(); oprd.pop();
        oprd.push(calculate(oprd1, oprt.top(), oprd2)); oprt.pop();
    }
    return oprd.top();

}

int main() {
    string expressions;
    while (cin >> expressions) {
        double result = evaluate(expressions);
        cout << result << endl;
    }
    return 0;
}