//: C05:FuncObject.cpp
// Simple function objects
#include <iostream>
using namespace std;

template<class UnaryFunc, typename T>
void callFunc(T& x, UnaryFunc f) {
    f(x);
}

void g(int& x) {
    x = 47;
}

struct UFunc {
    void operator()(int& x) {
        x = 48;
    }
};

int main() 
{
    int y = 0;
    callFunc(y, g);
    cout << y << endl;
    y = 0;
    callFunc(y, UFunc());
    cout << y << endl;
} ///:~
