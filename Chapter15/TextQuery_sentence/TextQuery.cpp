#include "TextQuery.h"
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

string make_plural(size_t i, const string &word, const string &c) {
    return (i > 1) ? word+c : word;
}

TextQuery::TextQuery(ifstream& in): file(new vector<string>) {
    string line;
    string sentence = "";
    while (getline(in, line)) {
        auto pos = line.find_first_of(".");
        if (pos != string::npos) {
            sentence += line.substr(0, pos+1);
            file->push_back(sentence);
            int n = file->size() - 1;
            istringstream sin(sentence);
            string word;
            while (sin >> word) {
                auto &lines = wm[word];
                if (!lines)
                    lines.reset(new set<line_no>);
                lines->insert(n);
            }
            sentence = line.substr(pos+1);
        } else {
            sentence += line;
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

std::ostream& print(std::ostream& out, const QueryResult& qr) {
    out << qr.word << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << std::endl;
    for (auto i : *(qr.lines)) {
        out << "\t(line " << i+1 << ") "
            << *(qr.file->begin() + i) << std::endl;
    }
    return out;
}