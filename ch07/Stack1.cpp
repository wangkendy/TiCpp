//: C07:Stack1.cpp
// Demonstrates the STL stack
#include "../require.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <vector>
#include <string>
using namespace std;

// Default: deque<string>:
typedef stack<string> Stack1;
// Use a vector<string>:
typedef stack<string, vector<string> > Stack2;
// Use a list<string>:
typedef stack<string, list<string> >Stack3;

int main(int argc, char* argv[])
{
	requireArgs(argc, 1);	// File name is argument
	ifstream in(argv[1]);
	assure(in, argv[1]);
	Stack1 textlines;	// Try the different ersions
	// Read file and store lines in the stack:
	string line;
	while (getline(in, line))
		textlines.push(line + "\n");
	// print lines from the stack and pop them:
	while (!textlines.empty()) {
		cout << textlines.top();
		textlines.pop();
	}
}	///:~
