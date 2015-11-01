#include <iostream>
#include <set>
using namespace std;
int main (void) {
	set<int> si;
	si.insert (10);
	si.insert (60);
	si.insert (10);
	si.insert (10);
	si.insert (20);
	for (set<int>::const_iterator it = si.begin ();
		it != si.end (); ++it)
		cout << *it << ' ';
	cout << endl;
	multiset<int> msi;
	msi.insert (10);
	msi.insert (60);
	msi.insert (10);
	msi.insert (10);
	msi.insert (20);
	for (multiset<int>::const_iterator it =
		msi.begin (); it != msi.end (); ++it)
		cout << *it << ' ';
	cout << endl;
	return 0;
}
