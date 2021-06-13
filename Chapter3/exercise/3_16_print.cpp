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
    for (auto i : v1)
        cout << i << " ";
    
    vector<int> v2(10);
    cout << endl << "len of v2: " << v2.size() << endl;
    for (auto i : v2) 
        cout << i << " ";
    
    vector<int> v3(10, 42);
    cout << endl << "len of v3: " << v3.size() << endl;
    for (auto i : v3) 
        cout << i << " ";
    
    vector<int> v4{10};
    cout << endl << "len of v4: " << v4.size() << endl;
    for (auto i : v4) 
        cout << i << " ";
    
    vector<int> v5{10, 42};
    cout << endl << "len of v5: " << v5.size() << endl;
    for (auto i : v5)
        cout << i << " ";
    
    vector<string> v6{10};
    cout << endl << "len of v6: " << v6.size() << endl;
    for (auto i : v6)
        cout << i << " ";
    
    vector<string> v7{10, "hi"};
    cout << endl << "len of v7: " << v7.size() << endl;
    for (auto i : v7)
        cout << i << " ";

    return 0;
}
