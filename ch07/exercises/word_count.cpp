//: C07:WordCount.cpp
//{L} StreamTokenizer
// Count occurrences of words using a map
#include "../StreamTokenizer.h"
#include "../../require.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Count {
	int i;
public:
	Count() : i(0) {}
    Count(int ii) : i(ii) {}
	void operator++(int) { i++; } // Post-increment
	int val() { return i; }
};

typedef map<string, Count> WordMap;
typedef WordMap::iterator WMIter;

int main(int argc, char* argv[])
{
	requireArgs(argc, 1);
	ifstream in(argv[1]);
	assure(in, argv[1]);
	StreamTokenizer words(in);
	WordMap wordmap;
	string word;
    WMIter it;
	while ((word = words.next()).size() != 0) {
		//wordmap[word]++;
        it = wordmap.find(word);
        if (it == wordmap.end()) {
            wordmap.insert(make_pair(word, Count(1)));
        } else {
            int old_val = it->second.val();
            wordmap.erase(it);
            wordmap.insert(make_pair(word, Count(old_val + 1)));
        }
    }
	for (WMIter w = wordmap.begin();
			w != wordmap.end(); w++)
		cout << (*w).first << ": "
			<< (*w).second.val() << endl;
} ///:~
