//: C05:RandGenTest.cpp
// A little test of the random number generator
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int sz = 10000;
    int v[sz];
    srand(time(0)); // Seed the random generator
    for (int i = 0; i < 300; i++) {
        // Using a naked pointer to function:
        generate(v, v + sz, std::rand);
        int count = count_if(v, v + sz,
            bind2nd(greater<int>(), RAND_MAX/2));
        cout << (((double)count)/(double)sz) * 100 << ' ';
    }
} ///:~
