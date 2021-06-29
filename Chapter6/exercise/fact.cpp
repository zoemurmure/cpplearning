#include "Chapter6.h"
long long fact(int n) {
    long long ret = 1;
    while (n > 1) {
        ret *= n--;
    }
    return ret;
}
