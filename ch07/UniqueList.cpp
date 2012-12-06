//: C07:UniqueList.cpp
// Testing list's unique() function
#include <list>
#include <iostream>
#include <iterator>
using namespace std;

int a[] = { 1, 3, 1, 4, 1, 5, 1 ,6, 1};
const int asz = sizeof a / sizeof *a;

int main()
{
	ostream_iterator<int> out(cout, " ");
	list<int> li(a, a + asz);
	li.unique();
	// Oops! No duplications removed:
	copy(li.begin(), li.end(), out);
	cout << endl;
	// Must sort it first:
	li.sort();
	copy(li.begin(), li.end(), out);
	cout << endl;
	// Now unique() will have an effect:
	li.unique();
	copy(li.begin(), li.end(), out);
	cout << endl;
} ///:~
