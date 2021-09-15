#ifndef STRING_H
#define STRING_H
#include <memory>
class String {
friend void print(const String&);
public:
    String(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const String&);
    String(const char*);
    String& operator= (const String&);
    String& operator+ (const String&);
    ~String();

    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char* begin() const  { return elements; }
    char* end() const { return first_free; }

private:
    static std::allocator<char> alloc;
    void chck_n_alloc() {
        if (size() == capacity()) reallocate(); }
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();
    void reallocate();
    void push_back(const char&);

    char *elements;
    char *first_free;
    char *cap;
};

void print(const String&);

#endif