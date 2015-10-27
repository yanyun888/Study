#include <iostream>
#include <queue>
#include <list>
using namespace std;
class IntCmp {
public:
	bool operator() (int const& a,
		int const& b) const {
		return a > b;
	}
};
int main (void) {
	priority_queue<int, deque<int>, IntCmp> pq;
	pq.push (50);
	pq.push (30);
	pq.push (60);
	pq.push (40);
	pq.push (70);
	while (! pq.empty ()) {
		cout << pq.top () << ' ';
		pq.pop ();
	}
	cout << endl;
	return 0;
}
