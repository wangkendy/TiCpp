//: C07:ListVsSet.cpp
// Comparing list and set performance
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

class Obj {
	int a[20];	// To take up extra space
	int val;
public:
	Obj() : val(rand() % 500) {}
	friend bool operator<(const Obj& a, const Obj& b) {
		return a.val < b.val;
	}

	friend bool operator==(const Obj& a, const Obj& b) {
		return a.val == b.val;
	}

	friend ostream& operator<<(ostream& os, const Obj& a) {
		return os << a.val;
	}
};

template<class Container>
void print(Container& c) {
	typename Container::iterator it;
	for (it = c.begin(); it != c.end(); it++)
		cout << *it << " ";
	cout << endl;
}

struct ObjGen {
	Obj operator()() { return Obj(); }
};

int main()
{
	const int sz = 50000;
	srand(time(0));
	list<Obj> lo;
	clock_t ticks = clock();
	generate_n(back_inserter(lo), sz, ObjGen());
	lo.sort();
	lo.unique();
	cout << "list:" << clock() - ticks << endl;
	set<Obj> so;
	ticks = clock();
	generate_n(inserter(so, so.begin()), sz, ObjGen());
	cout << "set:" << clock() - ticks << endl;
	print(lo);
	print(so);
} ///:~

