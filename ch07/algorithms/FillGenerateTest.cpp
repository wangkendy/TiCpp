//: C05:FillGenerateTest.cpp
// Demonstrates "fill" and "generate"
#include "Generators.h"
#include "PrintSequence.h"
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    vector<string> v1(5);
    fill(v1.begin(), v1.end(), "howdy");
    print(v1);

    vector<string> v2;
    fill_n(back_inserter(v2), 7, "bye");
    print_range(v2.begin(), v2.end(), "v2", " ");

    vector<int> v3(10);
    generate(v3.begin(), v3.end(), SkipGen(4,5));
    print(v3, "v3", " ");

    vector<int> v4;
    generate_n(back_inserter(v4), 15, URandGen(30));
    print(v4, "v4", " ");
} ///:~
