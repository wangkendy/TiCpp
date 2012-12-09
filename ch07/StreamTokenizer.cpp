//: C07:StreamTokenizer.cpp {O}
#include "StreamTokenizer.h"
using namespace std;

string StreamTokenizer::next() {
	string result;
	if (p != end) {
		insert_iterator<string>
			ii(result, result.begin());
		while (isDelimiter(*p) && p != end)
			p++;
		while (!isDelimiter(*p) && p != end)
			*ii++ = *p++;
	}
	return result;
} ///:~
