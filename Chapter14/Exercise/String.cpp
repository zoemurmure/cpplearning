#include "String.h"
#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

allocator<char> String::alloc;

ostream &operator<<(ostream &os, const String &s) {
    for (auto i = s.begin(); i != s.end(); ++i) {
        os << *i;
    }
    return os;
}

String::String(const String &s) {
    cout << "call copy constuctor of String" << endl;
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

String::String(const char *c) {
    size_t length = strlen(c);
    auto newdata = alloc_n_copy(c, c + length);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

String& String::operator= (const String &s) {
    cout << "call copy-assignment operator of String" << endl;
    auto newdata = alloc_n_copy(s.begin(), s.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

void String::push_back(const char &c) {
    chck_n_alloc();
    alloc.construct(first_free++, c);
}

String& String::operator+ (const String &s) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        push_back(*it);
    }
    return *this;
}

String::~String() {
    free();
}

void String::free() {
    if (elements) {
        for (auto i = first_free; i != elements;) {
            alloc.destroy(--i);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

pair<char*, char*> String::alloc_n_copy(const char *b, const char *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void String::reallocate() {
    size_t newcapacity = size() ? 2*size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (auto i = 0; i < newcapacity; ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = newdata + newcapacity;
}

String::String(String &&s) noexcept 
    : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    cout << "In move constructor" << endl;
    s.elements = s.first_free = s.cap = nullptr;
}

String& String::operator=(String &&rhs) noexcept {
    cout << "In move assignment" << endl;
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }

    return *this;
}