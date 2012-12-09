//: C07:TokenizerTest.cpp
//{L} StreamTokenizer
// Test StreamTokenizer
#include "StreamTokenizer.h"
#include "../require.h"
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main(int argc, char* argv[])
{
	requireArgs(argc, 1);
	ifstream in(argv[1]);
	assure(in, argv[1]);
	StreamTokenizer words(in);
	set<string> wordlist;
	string word;
	while ((word = words.next()).size() != 0)
		wordlist.insert(word);
	// Output results:
	copy(wordlist.begin(), wordlist.end(),
		ostream_iterator<string>(cout, "\n"));
} ///:~
