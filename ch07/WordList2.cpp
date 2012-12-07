//: C07:WordList2.cpp
// Eliminating strtok() from WordList.cpp
#include "../require.h"
#include <string>
#include <cstring>
#include <set>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

int main(int argc, char* argv[])
{
	requireArgs(argc, 1);
	ifstream in(argv[1]);
	assure(in, argv[1]);
	istreambuf_iterator<char> p(in), end;
	set<string> wordlist;
	while (p != end) {
		string word;
		insert_iterator<string> ii(word, word.begin());
		// Find the first alpha character:
		while (!isalpha(*p) && p != end)
			p++;
		// Copy until the first non-alpha character:
		while (isalpha(*p) && p != end)
			*ii++ = *p++;
		if (word.size() != 0)
			wordlist.insert(word);
	}
	// Output results:
	copy(wordlist.begin(), wordlist.end(),
			ostream_iterator<string>(cout, "\n"));
	return 0;
}
