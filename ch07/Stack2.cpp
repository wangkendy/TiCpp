//: C07:Stack2.cpp
// Converting a list to a stack
#include "../require.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <string>
using namespace std;

// Expects a stack:
template<class Stk>
void stackOut(Stk& s, ostream& os = cout) {
	while (!s.empty()) {
		os << s.top() << "\n";
		s.pop();
	}
}

class Line {
	string line;	// Without leading spaces
	int lspaces;	// Number of leading space
public:
	Line(string s) : line(s) {
		lspaces = line.find_first_not_of(' ');
		if (lspaces == string::npos)
			lspaces = 0;
		line = line.substr(lspaces);
	}
	friend ostream& operator<<(ostream& os, const Line& l) {
		for (int i = 0; i < l.lspaces; i++)
			os << ' ';
		return os << l.line;
	}
	// Other functions here...
};

int main(int argc, char* argv[])
{
	requireArgs(argc, 1);	// File name is argument
	ifstream in(argv[1]);
	assure(in, argv[1]);
	list<Line> lines;
	// Read file and store lines in the list:
	string s;
	while (getline(in, s))
		lines.push_front(s);
	// Turn the list into a stack for printing:
	stack<Line, list<Line> > stk(lines);
	stackOut(stk);
}	///:~
