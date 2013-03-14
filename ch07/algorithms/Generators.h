//: C05:Generators.h
// Different ways to fill sequences
#ifndef __GENERATORS_H__
#define __GENERATORS_H__
#include <set>
#include <cstdlib>
#include <cstring>
#include <ctime>

// A generator that can skip over numbers:
class SkipGen {
    int i;
    int skp;
public:
    SkipGen(int start = 0, int skip = 1) :
        i(start), skp(skip) {}
    int operator()() {
        int r = i;
        i += skp;
        return r;
    }
};

// Generato unique random numbers from 0 to mod:
class URandGen {
    std::set<int> used;
    int modulus;
public:
    URandGen(int mod) : modulus(mod) {
        std::srand(std::time(0));
    }
    int operator()() {
        while (true) {
            int i = (int) std::rand() % modulus;
            if (used.find(i) == used.end()) {
                used.insert(i);
                return i;
            }
        }
    }
};

// Produces random characters:
class CharGen {
    static const char* source; 
    static const int len;
public:
    CharGen() { std::srand(std::time(0)); }
    char operator()() {
        return source[std::rand() % len];
    }
};

#endif  // __GENERATORS_H__ ///~
