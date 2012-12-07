//: C07:WordList.cpp
// Display a list of words used in a document
#include "../require.h"
#include <string>
#include <cstring>
#include <set>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

const char* delimiters = "/ \t;()\"<>:{}+-=&*#.,\\~!@#$%";

int main(int argc, char* argv[])
{
	requireArgs(argc, 1);
	ifstream in(argv[1]);
	assure(in, argv[1]);
	set<string> wordlist;
	string line;
	while (getline(in, line)) {
		// Capture individual words:
		char *s = strtok((char*)line.c_str(), delimiters);
		while (s) {
			// Automatic type conversion:
			wordlist.insert(s);
			s = strtok(0, delimiters);
		}
	}
	// Output results:
	copy(wordlist.begin(), wordlist.end(), ostream_iterator<string>(cout, "\n"));
} ///:~
