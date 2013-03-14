//: C05:Binder4.cpp
// The bound argument does not have
// to be a compile-time constant
#include "copy_if.h"
#include "PrintSequence.h"
#include "../../require.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
using namespace std;

int boundedRand() {
    return rand() % 100;
}

int main(int argc, char* argv[])
{
    requireArgs(argc, 1, "usage: Binder4 int");
    const int sz = 20;
    int a[20], b[20] = {0};
    generate(a, a + sz, boundedRand);
    int* end = copy_if(a, a + sz, b,
        bind2nd(greater<int>(), atoi(argv[1])));

    // Sort for easier viewing:
    sort(a, a + sz);
    sort(b, end);
    print(a, a + sz, "array a", " ");
    print(b, end, "values greater than yours", " ");
} ///:~
