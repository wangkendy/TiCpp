//: C07:MultiSetWordCount.cpp
//{L} StreamTokenizer
// Count occurrences of words using a multiset
#include "StreamTokenizer.h"
#include "../require.h"
#include <string>
#include <set>
#include <fstream>
#include <iterator>
using namespace std;

int main(int argc, char* argv[])
{
	requireArgs(argc, 1);
	ifstream in(argv[1]);
	assure(in, argv[1]);
	StreamTokenizer words(in);
	miltiset<string> wordmset;
	string word;
	while ((word = words.next()).size() != 0)
		wordmset.insert(word);
	typedef multiset<string>::iterator MSit;
	MSit it = wordmset.begin();
	while (it != wordmset.end()) {
		pair<Msit, MSit> p = wordmset.equal_range(*it);
		int count = distance(p.first, p.second);
		cout << *it << ": " << count << endl;
		it = p.second;	// Move to the next word
	}
} ///:~
