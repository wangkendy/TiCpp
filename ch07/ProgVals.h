//: C07:ProgVals.h
// Program values can be changed by command line
#ifndef __PROGVALS_H__
#define __PROGVALS_H__
#include <map>
#include <iostream>
#include <string>

class ProgVals :
	public std::map<std::string, std::string> {
public:
	ProgVals(std::string defaults[][2], int sz);
	void parse(int argc, char* argv[],
		std::string usage,int offset = 1);
	void print(std::ostream& out = std::cout);
};
#endif // __PROGVALS_H__
