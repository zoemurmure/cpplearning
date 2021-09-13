#ifndef STRBLOB_H
#define STRBLOB_H
#include <vector>
#include <memory>
#include <string>

class StrBlob;
class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob&);
    StrBlob& operator= (const StrBlob&);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    std::string& front();
    std::string& back();
    const std::string& front() const;
    const std::string& back() const;
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):
        wptr(a.data), curr(sz) { }
    std::string& deref() const;
    StrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr(): curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0):
        wptr(a.data), curr(sz) { }
    const std::string& deref() const;
    ConstStrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};


#endif