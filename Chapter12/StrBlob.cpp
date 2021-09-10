#include "StrBlob.h"
using namespace std;

StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il):
    data(make_shared<vector<string>>(il)) { }

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

 string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

 string& StrBlob::back()  {
    check(0, "back on empty StrBlob");
    return data->back();
}

const string& StrBlob::front() const{
    check(0, "front on empty StrBlob");
    return data->front();
}

const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

int main() {
    StrBlob sb1;
    StrBlob sb2({"one", "two", "three"});
    string s1 = sb2.front();
    const string s2 = sb2.back();
    cout << s1 << " " << s2 << endl;
    cout << sb2.size() << endl;

    const StrBlob sb3 = {"1", "2", "3"};
    string s3 = sb3.front();
    cout << s3 << endl;
    return 0;
}