#ifndef STRBLOB_H
#define STRBLOB_H
#include <vector>
#include <memory>
#include <string>

class StrBlob;
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlobPtrPtr;

class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob&);
    StrBlob& operator= (const StrBlob&);
    std::string &operator[](std::size_t n) { return (*data)[n]; }
    const std::string &operator[](std::size_t n) const { return (*data)[n]; }
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) { data->push_back(t); }
    void push_back(std::string &&t) { data->push_back(std::move(t)); }
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

bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):
        wptr(a.data), curr(sz) { }
    std::string& deref() const;
    StrBlobPtr& incr();
    std::string &operator[](std::size_t n) { return (*wptr.lock())[curr+n]; }
    const std::string &operator[](std::size_t n) const { return (*wptr.lock())[curr+n]; }
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    StrBlobPtr& operator+=(int);
    StrBlobPtr& operator-=(int);
    StrBlobPtr operator+(int) const;
    StrBlobPtr operator-(int) const;
    std::string& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    std::string* operator->() const {
        return & this->operator*();
    }
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr(): curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0):
        wptr(a.data), curr(sz) { }
    const std::string& deref() const;
    ConstStrBlobPtr& incr();
    const std::string& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    const std::string* operator->() const {
        return & this->operator*();
    }
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

class StrBlobPtrPtr {
public:
    StrBlobPtrPtr(): ptr(nullptr) { }
    StrBlobPtrPtr(StrBlobPtr &p): ptr(&p) { }
    StrBlobPtr* operator->() const {
        return ptr;
    }
private:
    StrBlobPtr *ptr;
};


#endif