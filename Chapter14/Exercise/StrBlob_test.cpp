#include "StrBlob.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    //StrBlob sb1;
    //StrBlob sb2({"one", "two", "three"});
    //string s1 = sb2.front();
    //const string s2 = sb2.back();
    //cout << s1 << " " << s2 << endl;
    //cout << sb2.size() << endl;
//
    //const StrBlob sb3 = {"1", "2", "3"};
    //string s3 = sb3.front();
    //cout << s3 << endl;
    string file_name("text");
    ifstream in(file_name);
    string line;
    StrBlob sb1;
    while (getline(in, line)) {
        sb1.push_back(line);
    }
    StrBlob sb2 = sb1;
    sb2.push_back("test");

    StrBlobPtr iter = sb1.begin();
    for (size_t i = 0; i < sb1.size(); ++i, iter++) {
        cout << *iter << endl;
    }

    iter = sb2.begin();
    //for (size_t i = 0; i < sb2.size(); ++i, ++iter) {
    //    cout << *iter << endl;
    //}
    StrBlobPtrPtr sbpp(iter);
    StrBlobPtr *sbp = sbpp.operator->();
    for (size_t i = 0; i < sb2.size(); ++i, ++*sbp) {
        cout << **sbp << endl;
    }
    return 0;
}