//: C07:AssocGen.h
// The fill_n and generate_n equivalents
// for associative containers.
#ifndef __ASSOCGEN_H__
#define __ASSOCGEN_H__

template<class Assoc, class Count, class T>
void assocFill_n(Assoc& a, Count n, const T& val) {
	while (n-- > 0)
		a.insert(val);
}

template<class Assoc, class Count, class Gen>
void assocGen_n(Assoc& a, Count n, Gen g) {
	while (n-- > 0)
		a.insert(g());
}

#endif
///:~
