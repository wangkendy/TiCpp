//: C07:NoisyMap.cpp
// Mapping Noisy to Noisy
#include "Noisy.h"
#include <map>
using namespace std;

int main()
{
	map<Noisy, Noisy> mnn;
	Noisy n1, n2;
	cout << "\n--------\n";
	mnn[n1] = n2;
	cout << "\n--------\n";
	cout << mnn[n1] << endl;
	cout << "\n--------\n";
	map<int, int> mii;
	mii.insert(make_pair(12, 34));
	cout << "mii[12]" << mii[12] << endl;
	cout << "insert result:" << mii.insert(make_pair(12,12)).second << endl;
	cout << "mii[12]" << mii[12] << endl;
} ///:~
