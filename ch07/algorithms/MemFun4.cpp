//: C05:MemFun4.cpp
// Using the SGI STL compose1 function
#include "NumStringGen.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <iterator>
using namespace std;

int main()
{
    const int sz = 9;
    vector<string> vs(sz);
    // Fill it with random number strings:
    generate(vs.begin(), vs.end(), NumStringGen());
    copy(vs.begin(), vs.end(),
        ostream_iterator<string>(cout, "\t"));
    cout << endl;

    vector<double> vd;
    transform(vs.begin(), vs.end(), back_inserter(vd),
        compose1(ptr_fun(atof),
            mem_fun_ref(&string::c_str)));
    copy(vd.begin(), vd.end(),
        ostream_iterator<double>(cout, "\t"));
    cout << endl;
} ///:~
