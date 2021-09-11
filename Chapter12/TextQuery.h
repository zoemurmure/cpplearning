#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <set>
#include <map>
using line_no = std::vector<std::string>::size_type;

class QueryResult;
class TextQuery {
public:
    TextQuery() = default;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;

};

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