inline const string &
shorterString(const string &s1, const string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}

constexpr int new_sz() { return 42; }
constexpr int foo = new_sz();

constexpr size_t scale(size_t cnt) {
    return new_sz() * cnt;
}

// constant expression
int arr[scale(2)];

// not a constant expression
int i = 2;
int a2[scale(i)];