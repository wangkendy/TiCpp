//: C07:AssocInserter.cpp
// Using an insert_iterator so fill_n() and
// generate_n() can be used with associative
// containers
#include "SimpleGenerators.h"
#include <iterator>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main()
{
	set<int> s;
	fill_n(inserter(s, s.begin()), 10, 47);
	generate_n(inserter(s, s.begin()), 10,
		IncrGen<int>(12));
	copy(s.begin(), s.end(),
		ostream_iterator<int>(cout, "\n"));

	map<int, int> m;
	fill_n(inserter(m, m.begin()), 10, make_pair(90, 120));
	generate_n(inserter(m, m.begin()), 10,
		PairGen<int, int>(3, 9));
	typedef pair<int, int> PII;
	cout << PII(3,4) << endl;
	copy(m.begin(), m.end(),
		ostream_iterator<pair<int,int> >(cout, "\n"));
} ///:~
