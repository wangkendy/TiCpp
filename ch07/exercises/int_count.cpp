// int_count.cpp
// Create a generator that produces random int values between 0 and 20. Use
// this to fill a multiset<int>. Count the occurrences of each value, 
// following the example given in MultiSetWordCount.cpp.
#include <set>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

struct IntGen {
    IntGen() { srand(time(0)); }
    int operator()() {
        return rand() % 21;
    }
};

int main()
{
    multiset<int> msi;
    typedef multiset<int>::iterator MSIt;
    generate_n(inserter(msi, msi.begin()), 50, IntGen());
    MSIt it = msi.begin();
    while (it != msi.end()) {
        pair<MSIt, MSIt> p = msi.equal_range(*it);
        int count = distance(p.first, p.second);
        cout << *it << " : " << count << endl;
        it = p.second;  // Move to the next int
    }
    return 0;
}
