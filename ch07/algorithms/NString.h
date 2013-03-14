//: C05:NString.h
// A "numbered string" that indicates which
// occurrence this is of a particular word
#ifndef __NSTRING_H__
#define __NSTRING_H__
#include <string>
#include <map>
#include <iostream>

class NString {
    std::string s;
    int occurrence;
    struct Counter {
        int i;
        Counter() : i(0) {}
        Counter& operator++(int) {
            i++;
            return *this;
        }   // post increment
        operator int() { return i; }
    };

    // Keep track of the number of occurrences:
    typedef std::map<std::string, Counter> csmap;
    static csmap occurMap;
public:
    NString() : occurrence(0) {}
    NString(const std::string& x)
        : s(x), occurrence(occurMap[s]++) {}
    NString(const char* x)
        : s(x), occurrence(occurMap[s]++) {}
    // The synthesized operator= and
    // copy-constructor are OK here
    friend std::ostream& operator<<(
        std::ostream& os, const NString& ns) {
        return os << ns.s << " ["
            << ns.occurrence << "]";
    }

    // Need this for sorting. Notice it only
    // compares strings, not occurrences:
    friend bool operator<(const NString& l, const NString& r) {
        return l.s < r.s;
    }

    // For sorting with greater<NString>:
    friend bool operator>(const NString& l, const NString& r) {
        return l.s > r.s;
    }

    // To get at the string directly:
    operator const std::string&() const { return s; }
};
#endif  //__NSTRING_H__ ///:~
