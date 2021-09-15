#include "StrVec.h"
#include <iostream>
#include <utility>
using namespace std;

allocator<string> StrVec::alloc;

void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::pop_back() {
    if (size() > 0)
        alloc.destroy(first_free--);
}

pair<string*, string*> 
StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    //if (elements) {
    //    for (auto p = first_free; p != elements; )
    //        alloc.destroy(--p);
    //    alloc.deallocate(elements, cap - elements);
    //}
    if (element) {
        for_each(begin(), end(), [](string &p) { alloc.destroy(&p); });
        alloca.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() {
    free();
}

StrVec& StrVec::operator= (const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n) {
    while (capacity() < n) {
        reallocate();
    }
}

void StrVec::resize(size_t n, const string &s) {
    while (n > size()) {
        push_back(s);
    }
    while (n < size()) {
        pop_back();
    }
}

StrVec::StrVec(initializer_list<string>& il): StrVec() {
    for (const auto &s : il) {
        push_back(s);
    }
}

StrVec::StrVec(const StrVec &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator= (StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}