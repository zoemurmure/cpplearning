#include "StrBlob.h"
#include <algorithm>

using namespace std;

StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il):
    data(make_shared<vector<string>>(il)) { }

StrBlob::StrBlob(const StrBlob &rhs):
    data(make_shared<vector<string>>(*(rhs.data))) { }

StrBlob& StrBlob::operator= (const StrBlob &rhs) {
    //auto temp = new vector<string>(*(rhs.data));
    data = make_shared<vector<string>>(*(rhs.data));
    return *this;
}

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

 string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

 string& StrBlob::back()  {
    check(0, "back on empty StrBlob");
    return data->back();
}

const string& StrBlob::front() const{
    check(0, "front on empty StrBlob");
    return data->front();
}

const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw out_of_range(msg);
    }
    return ret;
}

string& StrBlobPtr::deref() const {
    auto p = check(curr, "deference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

shared_ptr<vector<string>>
ConstStrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw runtime_error("unbound ConstStrBlobPtr");
    }
    if (i >= ret->size()) {
        throw out_of_range(msg);
    }
    return ret;
}

const string& ConstStrBlobPtr::deref() const {
    auto p = check(curr, "deference past end");
    return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr() {
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.wptr.lock() == rhs.wptr.lock() &&
           lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}