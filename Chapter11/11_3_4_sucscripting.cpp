#include <map>
#include <iostream>
#include <string>
using namespace std;

int main() {
    map<string, size_t> word_count;
    // 输出式的访问也会增加元素
    cout << word_count["Anna"] << endl;
    for (const auto &i : word_count) {
        cout << i.first << " " << i.second << endl;
    }
    // at方式的访问不会增加元素, out_of_range
    cout << word_count.at("Bob") << endl;
    for (const auto &i : word_count) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}