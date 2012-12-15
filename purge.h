//: :purge.h
// Delete pointers in an STL sequence container
#ifndef __PURGE_H__
#define __PURGE_H__
#include <algorithm>

template<class Seq>
void purge(Seq& c) {
	typename Seq::iterator i;
	for (i = c.begin(); i != c.end(); i++) {
		delete *i;
		*i = 0;
	}
}

// Iterator version:
template<class InpIt>
void purge(InpIt begin, InpIt end) {
	while (begin != end) {
		delete *begin;
		*begin = 0;
		begin++;
	}
}

#endif	// __PURGE_H__ ///:~
