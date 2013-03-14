#include <iostream>

using namespace std;

template<typename T>
void print(const T& t1, const T& t2, const char* name = "") {
    if (*name != '\0')
        std::cout << name << ": " << std::endl;
    for (int i = t1; i < t2; i++)
        std::cout << i << " ";
    std::cout << endl;
}

int main()
{
    int a = 1, b = 10;
    print(a, b, "ab");
    return 0;
}
