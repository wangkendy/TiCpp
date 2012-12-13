//: C07:SimpleGenerators.h
// Generic generators, including
// one that creates pairs
#include <iostream>
#include <utility>

// A generator that increment its value:
template<typename T>
class IncrGen {
	T i;
public:
	IncrGen(T ii) : i(ii) {}
	T operator()() { return i++; }
};

// A generator that produces an STL pair<>:
template<typename T1, typename T2>
class PairGen {
	T1 i;
	T2 j;
public:
	PairGen(T1 ii, T2 jj) : i(ii), j(jj) {}
	std::pair<T1, T2> operator()() {
		return std::pair<T1, T2>(i++, j++);
	}
};

// A generic global operator<<
// for printing any STL pair<>:
namespace std 
{
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
	return os << p.first << "\t"
		<< p.second << std::endl;
}
}
///:~

