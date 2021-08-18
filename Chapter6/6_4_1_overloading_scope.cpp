#include <iostream>
#include <string>
#include <vector>
using namespace std;

string read();
void print(const string& s) { cout << s << endl; };
void print(double a) { cout << a << endl; };

void fooBar(int ival) {
    bool read = false;
    //string s = read();   // error:read is a bool variable
    void print(int);
    //print("Value: ");  // error:  print(const string&) is hidden 
    print(ival);
    print(3.14);    // ok: calls print(int); print(double) is hidden

}

int main(int argc, char **argv) {
    fooBar(5);
    return 0;
}
void print(int a) {
        cout << a << endl;
}
