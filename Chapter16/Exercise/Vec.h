#ifndef VEC_H 
#define VEC_H 
#include <string>
#include <memory>
#include <initializer_list>
#include <iostream>
#include <algorithm>
#include <utility>

//template <typename> class Vec;

template <typename T>
class Vec {
public:
    Vec(): elements(nullptr), first_free(nullptr), cap(nullptr) {
        std::cout << "Vec()" << std::endl;
    }
    Vec(const Vec&);
    Vec(std::initializer_list<T>);
    Vec& operator= (const Vec&);
    ~Vec();
    Vec(Vec&&) noexcept;
    Vec& operator= (Vec&&) noexcept;

    void push_back(const T&);
    void push_back(T&&);
    void pop_back();
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }
    void reserve(size_t);
    void resize(size_t n, const T &t = T());

private:
    static std::allocator<T> alloc;
    void chk_n_alloc() {
        if (size() == capacity()) reallocate(); }
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();

    T *elements;
    T *first_free;
    T *cap;
};

template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
Vec<T>::~Vec() {
    free();
}

template <typename T>
Vec<T>::Vec(std::initializer_list<T> il): Vec() {
    std::cout << "Vec(std::initializer_list<T> il)" << std::endl;
    for (const auto &t : il) {
        push_back(t);
    }
}

template <typename T>
Vec<T>::Vec(const Vec &v) {
    std::cout << "Vec(const Vec &v)" << std::endl;
    auto data = alloc_n_copy(v.begin(), v.end());
    elements = data.first;
    first_free = cap = data.second;
}

template <typename T>
Vec<T>::Vec(Vec &&v) noexcept
    : elements(v.elements), first_free(v.first_free), cap(v.cap) {
    std::cout << "Vec(Vec &&v)" << std::endl;
    v.elements = v.first_free = v.cap = nullptr;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs) {
    std::cout << "operator=(const Vec &rhs)" << std::endl;
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec &&rhs) noexcept {
    std::cout << "operator=(Vec &&rhs)" << std::endl;
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template <typename T>
void Vec<T>::push_back(const T &t) {
    chk_n_alloc();
    alloc.construct(first_free++, t);
}

template <typename T>
void Vec<T>::push_back(T &&t) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(t));
}

template <typename T>
void Vec<T>::pop_back() {
    if (size() > 0) {
        alloc.destroy(--first_free);
    }
}

template <typename T>
void Vec<T>::reserve(size_t n) {
    while (capacity() < n) {
        reallocate();
    }
}

template <typename T>
void Vec<T>::resize(size_t n, const T &t) {
    while (n > size()) {
        push_back(t);
    }
    while (n < size()) {
        pop_back();
    }
}

template <typename T>
void Vec<T>::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
                std::make_move_iterator(end()), first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::free() {
    if (elements) {
        std::for_each(begin(), end(), [](T &p){ alloc.destroy(&p); });
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}


#endif