//: C07:Stack3.cpp
// Using a vector as a stack; modified Stack1.cpp
#include "../require.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	requireArgs(argc, 1);
	ifstream in(argv[1]);
	assure(in, argv[1]);
	vector<string> textlines;
	string line;
	while (getline(in, line))
		textlines.push_back(line + "\n");
	while (!textlines.empty()) {
		cout << textlines.back();
		textlines.pop_back();
	}
	return 0;
} ///:~
