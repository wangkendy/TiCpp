//: C07:PriorityQueue1.cpp
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	priority_queue<int> pqi;
	srand(time(0));	// Seed random number generator
	for (int i = 0; i < 100; i++)
		pqi.push(rand() % 25);
	while (!pqi.empty()) {
		cout << pqi.top() << ' ';
		pqi.pop();
	}
} ///:~
