//: C05:PtrFun2.cpp
// Using ptr_fun() for two-argument functions
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
#include <cmath>
using namespace std;

double d[] = { 01.23, 91.370, 56.661,
    023.230, 19.959, 1.0, 3.14159};
const int dsz = sizeof d / sizeof *d;

int main()
{
    vector<double> vd;
    transform(d, d + dsz, back_inserter(vd),
        bind2nd(ptr_fun(::pow), 2.0));
    copy(vd.begin(), vd.end(),
        ostream_iterator<double>(cout, " "));
    cout << endl;
} ///:~
