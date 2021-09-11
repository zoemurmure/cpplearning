#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t n = 5;
    // combine allocating and constructing
    //string *const p = new string[n];
    //string s;
    //string *q = p;
    //while (cin >> s && q != p+n) {
    //    *q++ = s;
    //}
    //const size_t = q - p;
    //delete [] p;

    allocator<string> alloc;
    string *p = alloc.allocate(n);
    string *q = p;
    string s;
    while (cin >> s && q != p+n) {
        q = uninitialized_fill_n(q, 1, s);
        cout << *(q-1) << endl;
    }

    //allocator<string> alloc;
    //auto const p = alloc.allocate(n);
    //auto q = p;
    //alloc.construct(q++);
    //alloc.construct(q++, 10, 'c');
    //alloc.construct(q++, "hi");
    //cout << *(p+1) << endl;
    //while (q != p) {
    //    alloc.destroy(--q);
    //}
    //alloc.deallocate(p, n);

    //allocator<int> alloc;
    //vector<int> vi{1,2,3,4,5};
    //auto p = alloc.allocate(vi.size() * 2);
    //auto q = uninitialized_copy_n(vi.begin(), vi.size(), p);
    //auto r = uninitialized_fill_n(q, vi.size(), 42);
    //auto t = p;
    //while (t != r) {
    //    cout << *t++ << endl;
    //}
    return 0;
}