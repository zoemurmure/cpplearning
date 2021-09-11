#include "TextQuery.h"
#include <sstream>

using namespace std;

string make_plural(size_t i, const string &word, const string &c) {
    return (i > 1) ? word+c : word;
}

TextQuery::TextQuery(ifstream& in): file(new vector<string>) {
    string line;
    while (getline(in, line)) {
        file->push_back(line);
        int n = file->size() - 1;
        istringstream sin(line);
        string word;
        while (sin >> word) {
            //if (wm.count(word) == 0) {
            //    wm[word] = new set<line_no>;
            //}
            // wm[word]->insert(n);
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &word) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(word);
    if (loc == wm.end()) {
        return QueryResult(word, nodata, file);
    } else {
        return QueryResult(word, loc->second, file);
    }
}

ostream& print(ostream& out, const QueryResult& qr) {
    out << qr.word << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto i : *(qr.lines)) {
        out << "\t(line " << i+1 << ") "
            << *(qr.file->begin() + i) << endl;
    }
    return out;
}