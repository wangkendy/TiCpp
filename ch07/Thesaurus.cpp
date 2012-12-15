//: C07:Thesaurus.cpp
// A map of vectors
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <ctime>
using namespace std;

typedef map<string, vector<string> > Thesaurus;
typedef pair<string, vector<string> > TEntry;
typedef Thesaurus::iterator TIter;

namespace std{
ostream& operator<<(ostream& os, const TEntry& t) {
	os << t.first << ": ";
	copy(t.second.begin(), t.second.end(),
		ostream_iterator<string>(os, " "));
	return os;
}
}

// A generator for thesaurus test entries:
class ThesaurusGen {
	static const string letters;
	static int count;
public:
	int maxSize() { return letters.size(); }
	ThesaurusGen() { srand(time(0)); }
	TEntry operator()() {
		TEntry result;
		if (count >= maxSize()) count = 0;
		result.first = letters[count++];
		int entries = (rand() % 5) + 2;
		for (int i = 0; i < entries; i++) {
			int choice = rand() % maxSize();
			char cbuf[2] = { 0 };
			cbuf[0] = letters[choice];
			result.second.push_back(cbuf);
		}
		return result;
	}
};

int ThesaurusGen::count = 0;
const string ThesaurusGen::letters("ABCDEFGHIJKL"
	"MNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

int main()
{
	Thesaurus thesaurus;
	// Fill with 10 entries:
	generate_n(
		inserter(thesaurus, thesaurus.begin()),
		10, ThesaurusGen());

	// Print everything:
	copy(thesaurus.begin(), thesaurus.end(),
		ostream_iterator<TEntry>(cout, "\n"));

	// Ask for a "word" to look up:
	while (true) {
		cout << "Select a \"word\", 0 to quit: ";
		for (TIter it = thesaurus.begin();
			it != thesaurus.end(); it++)
			cout << (*it).first << ' ';
		cout << endl;
		string reply;
		cin >> reply;
		if (reply.at(0) == '0') return 0;	// Quit
		if (thesaurus.find(reply) == thesaurus.end())
			continue;	// Not in list, try again
		vector<string>& v = thesaurus[reply];
		copy(v.begin(), v.end(),
			ostream_iterator<string>(cout, " "));
		cout << endl;
	}
} ///:~
