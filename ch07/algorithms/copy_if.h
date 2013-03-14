//: C05:copy_if.h
// Roll your own STL-style algorithm
#ifndef __COPY_IF_H__
#define __COPY_IF_H__

template<typename ForwardIter,
    typename OutputIter, typename UnaryPred>
OutputIter copy_if(ForwardIter begin, ForwardIter end,
    OutputIter dest, UnaryPred f) {
    while (begin != end) {
        if (f(*begin))
            *dest++ = *begin;
        begin++;
    }
    return dest;
}
#endif  // __COPY_IF_H__ ///:~
