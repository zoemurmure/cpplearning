#include <iostream>
#include <string>
#include <vector>
using namespace std;

using arrT = int[10];
arrT* func(int i);
int (*func1(int i))[10]; // return a pointer to an array
int *func2(int i)[10];   // return an array of pointers
auto func3(int i) -> int(*)[10]; // return a pointer to an array

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
decltype(odd) *arrPtr(int i) {
    return (i % 2) ? &odd : &even; 
}

int main(int argc, char **argv) {
    int arr[10]; // an array of ten ints
    int *p1[10]; // an array of ten pointers
    int (*p2)[10]; // a pointer points to an array of ten ints


    return 0;
}
