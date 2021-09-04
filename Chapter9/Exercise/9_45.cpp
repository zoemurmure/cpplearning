#include <string>
#include <iostream>
using std::string;
using std::cin; using std::cout; using std::endl;

string changeName(const string &name, const string &prefix,
                  const string &suffix) {
    string newName = name;
    newName.insert(0, prefix + " ");
    newName.append(" " + suffix);
    return newName;

}

int main() {

    cout << changeName("Tom", "Mr.", "Jr.") << endl;
    return 0;
}