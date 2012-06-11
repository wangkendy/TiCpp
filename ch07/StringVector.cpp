//: C07:StringVector.cpp
// A vector of strings.
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "../require.h"
using namespace std;

int main(int argc, char* argv[])
{
	const char* fname = "StringVector.cpp";
	if(argc > 1) fname = argv[1];
	ifstream in(fname);
	assure(in, fname);
	vector<string> strings;
	string line;
	while (getline(in, line))
		strings.push_back(line);
	// Do something to the strings
	int i = 1;
	vector<string>::iterator w;
	for (w = strings.begin(); w != strings.end(); w++) {
		ostringstream ss;
		ss << i++;
		*w = ss.str() + ": " + *w;
	}
	// Now send them out;
	copy(strings.begin(), strings.end(),
		ostream_iterator<string>(cout, "\n"));
	// Since they aren't pointers, string
	// objects clean themselves up!
} ///:~
