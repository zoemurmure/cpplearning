#ifndef QUERY_H
#define QUERY_H
#include <string>
#include <memory>
#include <iostream>
#include "TextQuery.h"

class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const  = 0;
    virtual std::string rep() const = 0;
};


class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&);
    QueryResult eval(const TextQuery &t) const 
                    { return q->eval(t); }    
    std::string rep() const { return q->rep(); }
    ~Query();
    Query(const Query &rhs): q(rhs.q), count(rhs.count) {
        ++*count;
    }
    Query &operator=(const Query&);
private:
    Query(Query_base *&&query): q(query), count(new std::size_t(1)) { }
    Query_base *q;
    std::size_t *count;
};

inline
std::ostream &
operator<<(std::ostream &os, const Query &query) {
    return os << query.rep();
}

class WordQuery: public Query_base {
    friend class Query;
    WordQuery(const std::string &s): query_word(s) { }

    QueryResult eval(const TextQuery &t) const 
                    { return t.query(query_word); }
    std::string rep() const { return query_word; }
    std::string query_word;
};

inline
Query::Query(const std::string &s): 
    q(new WordQuery(s)), count(new std::size_t(1)) { }

class NotQuery: public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q): query(q) { }
    std::string rep() const  { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery &) const;   
    Query query;
};

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s):
            lhs(l), rhs(r), opSym(s) { }
    std::string rep() const {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym;    
};

class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "&") { }
    QueryResult eval(const TextQuery &) const;
};

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "|") { }
    QueryResult eval(const TextQuery &) const;
};

inline Query operator~(const Query &operand) {
    return new NotQuery(operand);
}

inline Query operator&(const Query &lhs, const Query &rhs) {
    return new AndQuery(lhs, rhs);
}

inline Query operator|(const Query &lhs, const Query &rhs) {
    return new OrQuery(lhs, rhs);
}

#endif