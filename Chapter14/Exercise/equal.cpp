#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Equal {
public:
    using vtype = int;
    Equal(vtype v): num(v) { }
    bool operator()(vtype a) {
        return a == num;
    }
private:
    vtype num;
};

int main() {
    vector<int> nums{1,43,7,2,1,5,34,1,45,0,1};
    replace_if(nums.begin(), nums.end(), Equal(1), 777);
    for (const int i : nums) {
        cout << i << endl;
    }
    return 0;
}