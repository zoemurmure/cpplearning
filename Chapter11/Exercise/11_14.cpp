#include <map>
#include <set>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

using Family = map<string, vector<pair<string, string>>>;

void addFamily(Family &f, const string &fname) {
    f.insert({fname, vector<pair<string, string>>()});
    return;
}

void addChild(Family &f, const string &fname, 
            const string &cname, const string &birth) {
    auto iter = f.find(fname);
    if (iter != f.end()) {
        iter->second.push_back(make_pair(cname, birth));
    } else {
        addFamily(f, fname);
        addChild(f, fname, cname, birth);
    }

    return;
}

int main() {
    Family families;
  addFamily(families, "Zhang");
  addFamily(families, "Li");
  addFamily(families, "Wang");
  addFamily(families, "Zhang");  // Error

  addChild(families, "Zhang", "San", "1991-01-01");
  addChild(families, "Zhang", "Bao", "1992-01-01");
  addChild(families, "Zhang", "Tian", "1993-01-01");
  addChild(families, "Li", "Si", "1991-01-11");
  addChild(families, "Wang", "Wu", "1991-06-01");
  addChild(families, "Wang", "San", "2002-01-01");
  addChild(families, "Zhao", "Liu", "1991-01-01");  // Error
  for (const auto &f : families) {
    for (const auto &n : f.second) {
        cout << f.first << " " 
        << n.first << " " << n.second << endl;
    }
  }
    return 0;
}