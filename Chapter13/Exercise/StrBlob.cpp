#include "StrBlob.h"

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il):
    data(std::make_shared<std::vector<std::string>>(il)) { }

StrBlob::StrBlob(const StrBlob &rhs):
    data(std::make_shared<std::vector<std::string>>(*(rhs.data))) { }

StrBlob& StrBlob::operator= (const StrBlob &rhs) {
    //auto temp = new std::vector<std::string>(*(rhs.data));
    data = std::make_shared<std::vector<std::string>>(*(rhs.data));
    return *this;
}

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

 std::string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

 std::string& StrBlob::back()  {
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string& StrBlob::front() const{
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "deference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound ConstStrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

const std::string& ConstStrBlobPtr::deref() const {
    auto p = check(curr, "deference past end");
    return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr() {
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}