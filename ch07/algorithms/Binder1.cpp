//: C05:Binder1.cpp
// Using STL "binders"
#include "Generators.h"
#include "copy_if.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
using namespace std;

int main()
{
    const int sz = 10;
    const int max = 40;
    vector<int> a(sz), r;
    URandGen urg(max);
    ostream_iterator<int> out(cout, " ");
    generate_n(a.begin(), sz, urg);
    copy(a.begin(), a.end(), out);
    vector<int>::iterator it;
    it = find_if(a.begin(), a.end(),
            bind2nd(less<int>(), 20));
    cout << "\n *it = " << *it << endl;
    // copy_if is not in the Standard C++ library
    // but is defined later in the chapter:
    copy_if(a.begin(), a.end(), back_inserter(r),
        bind2nd(less<int>(), 20));
    copy(r.begin(), r.end(), out);
    cout << endl;
    return 0;
} ///:~
