//: C05:MemFun3.cpp
// Using mem_fun()
#include "NumStringGen.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <functional>
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

    const char* cvp[sz];
    transform(vs.begin(), vs.end(), cvp,
        mem_fun_ref(&string::c_str));

    vector<double> vd;
    transform(cvp, cvp + sz, back_inserter(vd), std::atof);
    copy(vd.begin(), vd.end(),
        ostream_iterator<double>(cout, "\t"));
    cout << endl;
} ///:~
