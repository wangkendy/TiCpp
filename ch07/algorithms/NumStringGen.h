//: C05:NumStringGen.h
// A random number generator that produces
// strings representing floating-point numbers
#ifndef __NUMSTRINGGEN_H__
#define __NUMSTRINGGEN_H__
#include <string>
#include <cstdlib>
#include <ctime>

class NumStringGen {
    const int sz;   // Number of digits to make
public:
    NumStringGen(int ssz = 5) : sz(ssz) {
        std::srand(std::time(0));
    }

    std::string operator()() {
        static const char n[] = "0123456789";
        const int nsz = 10;
        std::string r(sz, ' ');
        for (int i = 0; i < sz; i++)
            if (i == sz /2 )
                r[i] = '.'; // Insert a decimal point
            else
                r[i] = n[std::rand() % nsz];
        return r;
    }
};

#endif  //__NUMSTRINGGEN_H__ ///:~

