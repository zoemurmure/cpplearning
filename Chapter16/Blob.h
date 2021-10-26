#ifndef BLOB_H
#define BLOB_H
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
    bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> 
class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>
        (const Blob&, const Blob&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    // constructors
    Blob(): data(std::make_shared<std::vector<T>>()) { }
    Blob(std::initializer_list<T> il):
        data(std::make_shared<std::vector<T>>(il)) { }
    // number of elements in the Blob
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements
    void push_back(const T &t) { data->push_back(t); }
    // move version
    void push_back(const T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    // element access
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    T& operator[](size_type i);  
    const T& operator[](size_type i) const; 
    BlobPtr<T> begin() { return BlobPtr<T>(*this); }
    BlobPtr<T> end() { return BlobPtr<T>(*this, size()); }
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }
};

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
    if (lhs.size() != rhs.size())
        return false;
    for (auto i = 0; i != lhs.size(); ++i) {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}

template <typename T> 
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T& Blob<T>::front() {
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T> 
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> 
T& Blob<T>::operator[](size_type i) {
    check(i, "index out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::front() const {
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T> 
const T& Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> 
const T& Blob<T>::operator[](size_type i) const {
    check(i, "index out of range");
    return (*data)[i];
}

template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T>
class BlobPtr {
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0):
        wptr(a.data), curr(sz) { }
    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr& operator++();  // prefix operators
    BlobPtr& operator--();
    BlobPtr operator++(int); // postfix operators
    BlobPtr operator--(int);
private:
    std::shared_ptr<std::vector<T>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.wptr.lock().get() == rhs.wptr.lock().get() && 
           lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs == rhs);
}

template <typename T>
std::shared_ptr<std::vector<T>> 
BlobPtr<T>::check(std::size_t n, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("Unbound BlobPtr");
    if (n >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr ret = *this;
    --*this;
    return ret;
}

#endif