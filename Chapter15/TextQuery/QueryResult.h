#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <set>

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult() = default;
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
            word(s), lines(p), file(f) { }
    std::set<line_no>::iterator begin() const { return lines->begin(); }
    std::set<line_no>::iterator end() const { return lines->end(); }
    std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
    std::string word;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

std::ostream& print(std::ostream&, const QueryResult&);


#endif