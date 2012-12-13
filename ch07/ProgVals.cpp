//: C07:ProgVals.cpp {O}
#include "ProgVals.h"
using namespace std;

ProgVals::ProgVals(string defaults[][2], int sz) {
	for (int i = 0; i < sz; i++)
		insert(make_pair(string(defaults[i][0]), 
					string(defaults[i][1])));
}

void ProgVals::parse(int argc, char* argv[],
	string usage, int offset) {
	// Parse and apply additional
	// command-line arguments:
	for (int i = offset; i < argc; i++) {
		string flag(argv[i]);
		int equal = flag.find('=');
		if (equal == string::npos) {
			cerr << "Command line error: " <<
				argv[i] << endl << usage << endl;
			continue;	// Next argument
		}
		string name = flag.substr(0, equal);
		string val = flag.substr(equal + 1);
		if (find(name) == end()) {
			cerr << name << endl << usage << endl;
			continue;	// Next argument
		}
		operator[](name) = val;
	}
}

void ProgVals::print(ostream& out) {
	out << "Program values:" << endl;
	for (iterator it = begin(); it != end(); it++)
		out << (*it).first << " = "
			<< (*it).second << endl;
} ///:~
