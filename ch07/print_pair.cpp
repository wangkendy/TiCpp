#include <iostream>
using namespace std;

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1,T2>& p) {
	return os << p.first << ":" << p.second << endl;
}

int main()
{
	pair<int,int> pii(12, 34);
	pair<int,float> pif(12, 34.56);
	cout << pii << endl;
	cout << pif << endl;
	return 0;
}
