//: C05:NoCompose.cpp
// Writing out the function objects explicitly
#include "copy_if.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <iterator>
#include <cstdlib>
#include <ctime>
using namespace std;

class Rgen {
    const int max;
public:
    Rgen(int mx = 100) : max(RAND_MAX / mx) {
        srand(time(0));
    }
    int operator()() {
        return rand() / max;
    }
};

class BoundTest {
    int top, bottom;
public:
    BoundTest(int b, int t) : bottom(b), top(t) {}
    bool operator() (int arg) {
        return (arg >= bottom) && (arg <= top);
    }
};

int main()
{
    vector<int> v(100);
    generate(v.begin(), v.end(), Rgen());
    vector<int> r;
    copy_if(v.begin(), v.end(), back_inserter(r),
        BoundTest(30, 40));
    sort(r.begin(), r.end());
    copy(r.begin(), r.end(),
        ostream_iterator<int>(cout, " "));
    cout << endl;
} ///:~
