//: C05:PrintSequence.h
// Prints the contents of any sequence
#ifndef __PRINTSEQUENCE_H__
#define __PRINTSEQUENCE_H__
#include <iostream>
#include <iterator>

template<typename InputIter>
void print(InputIter first, InputIter last,
    const char* nm = "", const char* sep = "\n",
    std::ostream& os = std::cout) {
    if (*nm != '\0')    // Only if you provide a string
        os << nm << ": " << sep;    // is this printed
    while (first != last)
        os << *first++ << sep;
    os << std::endl;
}

// Use template-templates to allow type deduction
// of the typename T:
//template<typename T, template<typename T, typename = std::allocator<T> > class C>
//void print(C<T>& c, const char* nm = "",
//    const char* sep = "\n",
//    std::ostream& os = std::cout) {
//    if (*nm != '\0')
//        os << nm << ": " << sep;
//    std::copy(c.begin(), c.end(),
//        std::ostream_iterator<T>(os, " "));
//    std::cout << std::endl;
//}

template<typename Container>
void print(Container& c, const char* nm = "",
    const char* sep = "\n",
    std::ostream& os = std::cout) {
    if (*nm != '\0')
        os << nm << ": " << sep;
    std::copy(c.begin(), c.end(),
        std::ostream_iterator<typename Container::value_type>(os, " "));
    std::cout << std::endl;
}

#endif  // __PRINTSEQUENCE_H__ ///:~
