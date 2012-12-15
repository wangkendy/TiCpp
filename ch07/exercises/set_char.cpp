// set_char.cpp
// Create a set<char>, then open a file (whose name is provided on the
// command line) and read that file in a char at a time, placing each
// char in the set. Print the result and observe the organization, and
// whether there are any letters in the alphabet that are not used in
// that particular file.
#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cerr << "uage: " << argv[0] << " <filename>" << endl;
        exit(1);
    }

    ifstream in(argv[1]);
    if (!in) {
        cerr << "Can not open file: " << argv[1] << endl;
    }

    string line;
    cin >> line;
    cout << line << endl;

    char ch;
    set<char> sc;
    while (!in.eof()) {
        in >> ch;
        sc.insert(ch);
    }

    set<char>::iterator it;
    for (it = sc.begin(); it != sc.end(); it++) {
        cout << *it;
    }
    cout << endl;
    return 0;
}
