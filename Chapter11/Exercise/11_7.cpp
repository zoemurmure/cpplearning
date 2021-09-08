#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

using Family = map<string, vector<string>>;

void addFamily(Family &f, const string &fname) {
    f.insert({fname, vector<string>()});
    return;
}

void addChild(Family &f, const string &fname, const string &cname) {
    auto iter = f.find(fname);
    if (iter != f.end()) {
        iter->second.push_back(cname);
    } else {
        addFamily(f, fname);
        addChild(f, fname, cname);
    }

    return;
}

int main() {
    Family families;
  addFamily(families, "Zhang");
  addFamily(families, "Li");
  addFamily(families, "Wang");
  addFamily(families, "Zhang");  // Error

  addChild(families, "Zhang", "San");
  addChild(families, "Zhang", "Bao");
  addChild(families, "Zhang", "Tian");
  addChild(families, "Li", "Si");
  addChild(families, "Wang", "Wu");
  addChild(families, "Wang", "San");
  addChild(families, "Zhao", "Liu");  // Error
  for (const auto &f : families) {
    for (const auto &n : f.second) {
        cout << f.first << " " << n << endl;
    }
  }
    return 0;
}