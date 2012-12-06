//: C07:Noisy.h
// A class to track various object activities.
#ifndef NOISY_H
#define NOISY_H
#include <iostream>
using std::endl;
using std::cout;
using std::ostream;

class Noisy {
	static long create, assign, copycons, destroy;
	long id;
public:
	Noisy() : id(create++) {
		cout << "d[" << id << "]" << endl;
	};
	Noisy(const Noisy& rv) : id(rv.id) {
		cout << "c[" << id << "]" << endl;
		++copycons;
	}
	Noisy& operator=(const Noisy& rv) {
		cout << "(" << id << ")=[" << rv.id << "]" << endl;
		id = rv.id;
		++assign;
		return *this;
	}

	friend bool operator<(const Noisy& lv, const Noisy& rv) {
		return lv.id < rv.id;
	}

	friend bool operator==(const Noisy& lv, const Noisy& rv) {
		return lv.id == rv.id;
	}

	~Noisy() {
		cout << "~[" << id << "]" << endl;
		++destroy;
	}

	friend ostream& operator<<(ostream& os, const Noisy& n) {
		return os << n.id;
	}
	friend class NoisyReport;
};

struct NoisyGen {
	Noisy operator()() { return Noisy(); }
};

// A Singleton. Will automatically report the
// statistics as the program terminates:
class NoisyReport {
	static NoisyReport nr;
	NoisyReport() {} // Private cnstructor
	NoisyReport& operator=(NoisyReport&); // Disallowed
	NoisyReport(const NoisyReport&);	// Disallowed
public:
	~NoisyReport() {
		cout << "\n---------------------\n"
			 << "Noisy creations: " << Noisy::create
			 << "\nCopy-Constructions: " << Noisy::copycons
			 << "\nAssignments: " << Noisy::assign
			 << "\nDestructions: " << Noisy::destroy << endl;
	}
};

#endif // NOISY_H ///:~
