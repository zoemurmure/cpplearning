#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector<int> v1;
    cout << "len of v1: " << v1.size() << endl;
    for (auto it = v1.cbegin(); it != v1.cend(); ++it)
        cout << *it << " ";
    
    vector<int> v2(10);
    cout << endl << "len of v2: " << v2.size() << endl;
    for (auto it = v2.cbegin(); it != v2.cend(); ++it) 
        cout << *it << " ";
    
    vector<int> v3(10, 42);
    cout << endl << "len of v3: " << v3.size() << endl;
    for (auto it = v3.cbegin(); it != v3.cend(); ++it) 
        cout << *it << " ";
    
    vector<int> v4{10};
    cout << endl << "len of v4: " << v4.size() << endl;
    for (auto it = v4.cbegin(); it != v4.cend(); ++it) 
        cout << *it << " ";
    
    vector<int> v5{10, 42};
    cout << endl << "len of v5: " << v5.size() << endl;
    for (auto it = v5.cbegin(); it != v5.cend(); ++it)
        cout << *it << " ";
    
    vector<string> v6{10};
    cout << endl << "len of v6: " << v6.size() << endl;
    for (auto it = v6.cbegin(); it != v6.cend(); ++it)
        cout << *it << " ";
    
    vector<string> v7{10, "hi"};
    cout << endl << "len of v7: " << v7.size() << endl;
    for (auto it = v7.cbegin(); it != v7.cend(); ++it)
        cout << *it << " ";

    return 0;
}
