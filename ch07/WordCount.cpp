//: C07:WordCount.cpp
//{L} StreamTokenizer
// Count occurrences of words using a map
#include "StreamTokenizer.h"
#include "../require.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Count {
	int i;
public:
	Count() : i(0) {}
	void operator++(int) { i++; } // Post-increment
	int val() { return i; }
};

typedef map<string, Count> WordMap;
typedef WordMap::iterator WMIter;

int main(int argc, char* argv[])
{
	requireArgs(argc, 1);
	ifstream in(argv[1]);
	assure(in, argv[1]);
	StreamTokenizer words(in);
	WordMap wordmap;
	string word;
	while ((word = words.next()).size() != 0)
		wordmap[word]++;
	for (WMIter w = wordmap.begin();
			w != wordmap.end(); w++)
		cout << (*w).first << ": "
			<< (*w).second.val() << endl;
} ///:~
